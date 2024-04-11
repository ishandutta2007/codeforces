#include<cstdio>

int n;

int main(){
	scanf("%d",&n);
	if(n%4==0)
		printf("1 A");
	else if(n%4==1)
		printf("0 A");
	else if(n%4==2)
		printf("1 B");
	else
		printf("2 A");
}