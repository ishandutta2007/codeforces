#include<stdio.h>
#pragma warning(disable:4996)

int main(){
	int A,B,a,b,i;
	scanf("%d%d",&A,&B);
	for(a=1;a*a<=A*A;a++){
		for(b=1;a*a+b*b<=A*A;b++){
			if(a*a+b*b==A*A && (a*B)%A==0 && (b*B)%A==0 && a!=b*B/A){
				puts("YES");
				printf("%d %d\n%d %d\n%d %d\n",-b,a,0,0,a*B/A,b*B/A);
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}