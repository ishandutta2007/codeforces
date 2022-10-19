#include<iostream>
#include<cstdio>
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
int m[100001],a[100001];
signed main()
{
	int n,ans,nmax,tans,tpos;
	n=read();
	for(int i=1;i<=n;i++)m[i]=read();
	m[0]=2000000000;
	tans=0;
	for(int i=0;i<=n;i++)
	{
		if(i!=0)ans=m[i];
		else ans=0;
		nmax=m[i];
		for(int j=i-1;j>=1;j--)
		{
			nmax=min(nmax,m[j]);
			ans+=nmax;
		}
		nmax=m[i];
		for(int j=i+1;j<=n;j++)
		{
			nmax=min(nmax,m[j]);
			ans+=nmax;
		}
		if(ans>tans)
		{
			tans=ans;
			tpos=i;
		}
	}
	nmax=m[tpos];
	for(int j=tpos-1;j>=1;j--)
	{
		nmax=min(nmax,m[j]);
		a[j]=nmax;
	}
	nmax=m[tpos];
	for(int j=tpos+1;j<=n;j++)
	{
		nmax=min(nmax,m[j]);
		a[j]=nmax;
	}
	a[tpos]=m[tpos];
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	return 0;
}