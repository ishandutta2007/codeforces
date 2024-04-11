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
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)printf("(");
			printf(")");
			for(int j=1;j<=n-i;j++)printf("(");
			for(int j=1;j<=n-1;j++)printf(")");
			printf("\n");
		}
	}
	return 0;
}