#include<cstdio>

int n;

int main(){
	scanf("%d",&n);
	printf("%d\n",n/2+1);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",(i+1)/2,i/2+1);
}