#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int status;
	switch(pid = fork()) {
	case 0 :
		switch(fork()) {
		case 0 :
			sleep(1);
			printf("child ppid : %ld\n", (long)getppid());
			break;
		default :
			printf("parent pid : %ld\n", (long)getpid());
			exit(0);
		}
	default :
		wait(&status);
		sleep(2);
		exit(0);
	}
}
