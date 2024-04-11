#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n/2*(n+1>>1));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(i+j&1)
				printf("%d %d\n",i,j);
}