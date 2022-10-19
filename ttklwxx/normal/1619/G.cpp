#include<iostream>
#include<cstdio>
#include<algorithm>
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
int fa[200005],minn[200005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
struct sth
{
	int x,y,id;
}s[200005];
bool bi(struct sth c,struct sth d)
{
	if(c.x!=d.x)return c.x<d.x;
	return c.y<d.y;
}
bool bibi(struct sth c,struct sth d)
{
	if(c.y!=d.y)return c.y<d.y;
	return c.x<d.x;
}
int n;
bool check(int mid)
{
	int sl=0;
	for(int i=1;i<=n;i++)
	{
		if(minn[i]>mid)sl++;
	}
	if(sl<=mid+1)return true;
	return false;
}
int main()
{
	int t,k,x,y,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)
		{
			s[i].x=read();
			s[i].y=read();
			s[i].id=i;
			fa[i]=i;
			minn[i]=read();
		}
		sort(s+1,s+n+1,bi);
		for(int i=2;i<=n;i++)
		{
			if(s[i].x==s[i-1].x&&s[i].y-s[i-1].y<=k)
			{
				x=findf(s[i].id);
				y=findf(s[i-1].id);
				if(x!=y)
				{
					fa[x]=y;
					minn[y]=min(minn[y],minn[x]);
					minn[x]=0;
				}
			}
		}
		sort(s+1,s+n+1,bibi);
		for(int i=2;i<=n;i++)
		{
			if(s[i].y==s[i-1].y&&s[i].x-s[i-1].x<=k)
			{
				x=findf(s[i].id);
				y=findf(s[i-1].id);
				if(x!=y)
				{
					fa[x]=y;
					minn[y]=min(minn[y],minn[x]);
					minn[x]=0;
				}
			}
		}
		//for(int i=1;i<=n;i++)printf("%d ",fa[i]);
		//printf("\n");
		l=0;
		r=1000000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
}