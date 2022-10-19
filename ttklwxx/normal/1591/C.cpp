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
int xz[200005],cz;
int xf[200005],cf;
int x[200005];
int jdz(int sth)
{
	if(sth<0)return -sth;
	return sth;
}
signed main()
{
	int t,n,k,ans=0,maxn=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		cz=cf=0;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			x[i]=read();
			maxn=max(maxn,jdz(x[i]));
			if(x[i]>0)xz[++cz]=x[i];
			else xf[++cf]=-x[i];
		}
		sort(xf+1,xf+cf+1);
		sort(xz+1,xz+cz+1);
		ans=0;
		for(int i=cz;i>=1;i-=k)ans+=xz[i]*2;
		for(int i=cf;i>=1;i-=k)ans+=xf[i]*2;
		printf("%lld\n",ans-maxn);
	}
	return 0;
}