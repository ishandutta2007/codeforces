#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[200005];
int nr[200005],qzr[200005];
int kz[200005];
int nans[200005];
int qans[200005];
struct query
{
	int x,y,id;
}q[200005];
bool bi(struct query c,struct query d)
{
	return c.y<d.y;
}
signed main()
{
	int n,m,ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()-i;
	int tr=1;
	for(int i=1;i<=n;i++)
	{
		while(tr<n&&a[tr+1]>=1-i)tr++;
		nr[i]=tr;
		ans+=(tr-i+1);
		//printf("%d\n",tr);
	}
	m=read();
//	printf("orz\n");
	qzr[0]=0;
	for(int i=1;i<=n;i++)qzr[i]=qzr[i-1]+nr[i];
	int sth=1;
	for(int i=1;i<=n;i++)
	{
		sth=max(sth,nr[i]+2);
		while(sth<=n&&a[sth]>=1-i)sth++;
		//printf("???%d\n",sth);
		sth=min(sth,n+1);
		kz[i]=sth-1-nr[i];
	}
	int x,y;
	for(int i=1;i<=m;i++)
	{
		q[i].x=read();
		q[i].y=read()-q[i].x;
		q[i].id=i;
	}
	sort(q+1,q+m+1,bi);
	int now=n;
	for(int i=1;i<=m;i++)
	{
		x=q[i].x;
		y=q[i].y;
		while(now>=1&&y>=1-now)
		{
			if(nr[now]<=n)nans[nr[now]+1]+=kz[now];
			now--;
		}
		if(y==a[x])
		{
			qans[q[i].id]=ans;
			continue;
		}
		if(y>a[x])
		{
			qans[q[i].id]=ans+nans[x];
			continue;
		}
		if(y<a[x])
		{
			int nowr=-y;
			if(nowr<1)nowr=0;
			if(nowr>n)nowr=n;
			int nowl=lower_bound(nr+1,nr+n+1,x)-nr;
			//printf("%lld %lld\n",nowl,nowr);
			if(nowl>nowr)
			{
				qans[q[i].id]=ans;
				continue;
			}
			qans[q[i].id]=ans-qzr[nowr]+qzr[nowl-1]+(nowr-nowl+1)*(x-1);
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",qans[i]);
	return 0;
}