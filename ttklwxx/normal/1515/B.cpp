#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=sqrt(n/4);
		if(4*x*x==n)
		{
			printf("YES\n");
			continue;
		}
		x=sqrt(n/2);
		if(2*x*x==n)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}