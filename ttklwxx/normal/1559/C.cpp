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
int a[200005];
int main()
{
	int t,n,x;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		x=1;
		while(a[x]==0&&x<=n)x++;
		for(int i=1;i<=x-1;i++)printf("%d ",i);
		printf("%d ",n+1);
		for(int i=x;i<=n;i++)printf("%d ",i);
		printf("\n");
	}
	return 0;
}