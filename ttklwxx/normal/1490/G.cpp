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
int a[200005],x[200005],pos[200005],ans[200005],posp[200005],p[200005],ys[200005];
bool bi(int c,int d)
{
	return x[c]<x[d];
}
bool biys(int c,int d)
{
	return ys[c]<ys[d];
}
signed main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	int n,m,s,sth,maxn=-1121131433448687LL;
	n=read();
	m=read();
	s=0;
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i],maxn=max(maxn,s);
	for(int i=1;i<=m;i++)x[i]=read(),pos[i]=i,posp[i]=i,ans[i]=0;
	if(s<=0)
	{
		sort(pos+1,pos+m+1,bi);
		s=0;
		sth=1;
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			while(sth<=m&&s>=x[pos[sth]])ans[pos[sth]]=i,sth++;
		}
		for(int i=1;i<=m;i++)
		{
			if(ans[i]==0)printf("-1 ");
			else printf("%lld ",ans[i]-1);
		}
		printf("\n");
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(x[i]<=maxn)
			{
				p[i]=0;
				ys[i]=x[i];
				continue;
			}
			p[i]=(x[i]-maxn-1)/s+1;
			ys[i]=x[i]-p[i]*s;
		}
		s=0;
		sth=1;
		sort(posp+1,posp+m+1,biys);
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			while(sth<=m&&s>=ys[posp[sth]])ans[posp[sth]]=i,sth++;
		}
		for(int i=1;i<=m;i++)
		{
			printf("%lld ",ans[i]+p[i]*n-1);
		}
		printf("\n");
	}
	}
	return 0;
}