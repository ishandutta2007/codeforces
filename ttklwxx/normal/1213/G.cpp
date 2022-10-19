#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
struct query
{
	int x,bh,ans;
}q[200005];
bool bi(struct query c,struct query d)
{
	return c.x<d.x;
}
bool bibi(struct query c,struct query d)
{
	return c.bh<d.bh;
}
struct bbian
{
	int u,v,qz;
}a[200005];
bool bib(struct bbian c,struct bbian d)
{
	return c.qz<d.qz;
}
int fa[200005],siz[200005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
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
signed main()
{
	int n,m,ans=0;
	n=read();
	m=read();
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=n-1;i++)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].qz=read();
	}
	sort(a+1,a+n,bib);
	for(int i=1;i<=m;i++)
	{
		q[i].bh=i;
		q[i].x=read();
	}
	sort(q+1,q+m+1,bi);
	int y=1,sx=0,sy=0;
	for(int i=1;i<=m;i++)
	{
		for(;a[y].qz<=q[i].x&&y<=n;y++)
		{
			sx=findf(a[y].u);
			sy=findf(a[y].v);
			if(sx==sy)continue;
			ans=ans-siz[sx]*(siz[sx]-1)/2-siz[sy]*(siz[sy]-1)/2+(siz[sx]+siz[sy])*(siz[sx]+siz[sy]-1)/2;
			fa[sx]=sy;
			siz[sy]+=siz[sx];
		}
		q[i].ans=ans;
	}
	sort(q+1,q+m+1,bibi);
	for(int i=1;i<=m;i++)printf("%lld ",q[i].ans);
}