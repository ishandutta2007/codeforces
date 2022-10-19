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
	for(int i=1;i<=t;i++)
	{
		n=read();
		if(n%2==0)
		{
			for(int i=1;i<=n/2;i++)printf("1");
			printf("\n");
		}
		else
		{
			printf("7");
			for(int i=1;i<=n/2-1;i++)printf("1");
			printf("\n");
		}
	}
    return 0;
}