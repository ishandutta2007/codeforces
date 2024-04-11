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
int m[600001],sta[600001],len[600001],ttop,ans[600001],a[600001];
signed main()
{
	int n,tans,tpos,x;
	n=read();
	for(int i=1;i<=n;i++)m[i]=read();
	tans=0;
	ans[0]=0;
	for(int i=1;i<=n;i++)
	{
		x=1;
		while(ttop>=1&&m[sta[ttop]]>=m[i])tans-=len[ttop]*m[sta[ttop]],x+=len[ttop],ttop--;
		sta[++ttop]=i;
		len[ttop]=x;
		tans+=m[sta[ttop]]*len[ttop];
		ans[i]=tans;
	}
	tans=0;
	ttop=0;
	for(int i=n;i>=1;i--)
	{
		x=1;
		while(ttop>=1&&m[sta[ttop]]>=m[i])tans-=len[ttop]*m[sta[ttop]],x+=len[ttop],ttop--;
		sta[++ttop]=i;
		len[ttop]=x;
		tans+=m[sta[ttop]]*len[ttop];
		ans[i]+=tans;
		ans[i]-=m[i];
	}
    tans=0;
    for(int i=1;i<=n;i++)if(ans[i]>tans)tans=ans[i],tpos=i;
	int nmax; 
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