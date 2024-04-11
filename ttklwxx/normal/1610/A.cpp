//Chapter I: At The Precipice
#include<iostream>
#include<cstdio>
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
	int t,n,m;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		if(n==1&&m==1)
		{
			printf("0\n");
			continue;
		}
		if(n==1||m==1)
		{
			printf("1\n");
			continue;
		}
		if(n==2||m==2)
		{
			printf("2\n");
			continue;
		}
		printf("2\n");
	}
	return 0;
}