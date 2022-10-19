#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
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
int a[200005],b[200005],pos[200005];
bool bi(int x,int y)
{
	return b[x]-a[x]<b[y]-a[y];
}
struct sth
{
	int dx,id;
	sth(int x=0,int y=0)
	{
		dx=x;
		id=y;
	}
};
bool operator<(struct sth x,struct sth y)
{
	if(x.dx!=y.dx)return x.dx>y.dx;
	return x.id>y.id;
}
priority_queue<struct sth>pq;
int qz[200005],hz[200005];
signed main()
{
	int n,p,s;
	n=read();
	p=read();
	s=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	for(int i=1;i<=n;i++)pos[i]=i;
	struct sth gre;
	sort(pos+1,pos+n+1,bi);
	for(int i=1;i<=n;i++)
	{
		pq.push(sth(a[pos[i]],pos[i]));
		qz[i]=qz[i-1]+a[pos[i]];
		if(i>p)
		{
			qz[i]-=pq.top().dx;
			pq.pop();
		}
	}
	while(!pq.empty())pq.pop();
	for(int i=n;i>=1;i--)
	{
		pq.push(sth(b[pos[i]],pos[i]));
		hz[i]=hz[i+1]+b[pos[i]];
		if(i<=n-s)
		{
			hz[i]-=pq.top().dx;
			pq.pop();
		}
	}
	int maxn=0,maxp=0;
	for(int i=p+1;i<=n-s+1;i++)
	{
		if(hz[i]+qz[i-1]>maxn)
		{
			maxn=hz[i]+qz[i-1];
			maxp=i;
		}
	}
	printf("%lld\n",maxn);
	while(!pq.empty())pq.pop();
	for(int i=1;i<=maxp-1;i++)
	{
		pq.push(sth(a[pos[i]],pos[i]));
		if(i>p)
		{
			pq.pop();
		}
	}
	while(!pq.empty())
	{
		printf("%lld ",pq.top().id);
		pq.pop();
	}
	printf("\n");
	for(int i=n;i>=maxp;i--)
	{
		pq.push(sth(b[pos[i]],pos[i]));
		if(i<=n-s)
		{
			pq.pop();
		}
	}
	while(!pq.empty())
	{
		printf("%lld ",pq.top().id);
		pq.pop();
	}
	printf("\n");
	return 0;
}