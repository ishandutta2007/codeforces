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
struct dian
{
	int x,y;
}a[300005];
bool bi1(struct dian c,struct dian d)
{
	return c.x<d.x;
}
bool bi2(struct dian c,struct dian d)
{
	return c.y<d.y;
}
int x[300005],y[300005];
int qzx[200005],qzy[200005];
int to[1000005];
signed main()
{
	int t,n,m,k,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=m;i++)y[i]=read();
		for(int i=1;i<=k;i++)
		{
			a[i].x=read();
			a[i].y=read();
		}
		sort(a+1,a+k+1,bi1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			qzx[i]=qzx[i-1];
			while(a[qzx[i]+1].x<x[i]&&qzx[i]<=k-1)qzx[i]++,to[a[qzx[i]].y]++;
			ans=(ans+(qzx[i]-qzx[i-1])*(qzx[i]-qzx[i-1]-1)/2);
			for(int j=qzx[i-1]+1;j<=qzx[i];j++)
			{
				ans=(ans-(to[a[j].y])*(to[a[j].y]-1)/2);
				to[a[j].y]=0;
			}
			while(qzx[i]<=k-1&&a[qzx[i]+1].x==x[i])qzx[i]++;
		}
		sort(a+1,a+k+1,bi2);
		for(int i=1;i<=m;i++)
		{
			qzy[i]=qzy[i-1];
			while(qzy[i]<=k-1&&a[qzy[i]+1].y<y[i])qzy[i]++,to[a[qzy[i]].x]++;
			ans=(ans+(qzy[i]-qzy[i-1])*(qzy[i]-qzy[i-1]-1)/2);
			for(int j=qzy[i-1]+1;j<=qzy[i];j++)
			{
				ans=(ans-(to[a[j].x])*(to[a[j].x]-1)/2);
				to[a[j].x]=0;
			}
			while(qzy[i]<=k-1&&a[qzy[i]+1].y==y[i])qzy[i]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}