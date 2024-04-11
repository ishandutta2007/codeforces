#include<bits/stdc++.h>

int n;

int main(){
	scanf("%d",&n);
	if(n==1)
		return puts("1\n1 1"),0;
	int x=n;
	while(x*2-1+x>n)
		x--;
	printf("%d\n",n-x);
	for(int i=1;i<=x;i++)
		printf("%d %d\n",i,x-i+1);
	for(int i=1;i<=x-1;i++)
		printf("%d %d\n",x+i,x+x-i);
	for(int i=x+x;i<=n-x;i++)
		printf("%d %d\n",i,i);
}