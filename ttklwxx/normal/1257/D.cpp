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
int a[200001],maxn[200001];
int main()
{
	int t,n,m,x,y,ans,maxg;
	t=read();
	for(int i=1;i<=t;i++)
	{
		maxg=0;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),maxg=max(maxg,a[i]);
		m=read();
		for(int i=1;i<=m;i++)
		{
			x=read();
			y=read();
			maxn[y]=max(maxn[y],x);
		}
		for(int i=n-1;i>=1;i--)maxn[i]=max(maxn[i],maxn[i+1]);
		if(maxn[1]<maxg)
		{
			printf("-1\n");
			for(int i=1;i<=n;i++)maxn[i]=0;
			continue;
		}
		x=0;
		ans=1;
		maxg=0;
		for(int i=1;i<=n;i++)
		{
			x++;
			maxg=max(a[i],maxg);
			if(maxn[x]<maxg)
			{
				x=1;
				ans++;
				maxg=a[i];
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)maxn[i]=0;
	}
}