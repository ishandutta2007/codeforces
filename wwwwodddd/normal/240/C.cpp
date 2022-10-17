#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int lg(int n)
{
	if(n==1)
		return 0;
	return lg(n+1>>1)+1;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d",&n);
	int z=lg(n);
	printf("%d\n",z);
	for(int i=0;i<z;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
			if(j>>i&1)
				c++;
		printf("%d ",c);
		for(int j=0;j<n;j++)
			if(j>>i&1)
				printf("%d ",j+1);
		puts("");
	}
}