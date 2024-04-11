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
bool vis[200005];
int main()
{
	int t,n,m,x,y,z;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)vis[i]=false;
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			z=read();
			vis[y]=true;
		}
		x=0;
		for(int i=1;i<=n;i++)if(vis[i]==false)
		{
			x=i;
			break;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=x)printf("%d %d\n",i,x);
		}
	}
	return 0;
}