#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define mod 998244353
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
int p[100005];
int main()
{
	int t,n,m,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)p[i]=read();
		x=m;
		for(int i=1;i<=m;i++)if(p[i]<=m)x--;
		printf("%d\n",x);
	}
	return 0;
}