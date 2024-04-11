#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int f[4020],x,n;
int main()
{
	scanf("%d",&n);
	memset(f,0xc0,sizeof f);
	f[0]=0;
	for(int _=0;_<3;_++)
	{
		scanf("%d",&x);
		for(int i=x;i<=n;i++)
			f[i]=max(f[i],f[i-x]+1);
	}
	printf("%d",f[n]);
	return 0;
}