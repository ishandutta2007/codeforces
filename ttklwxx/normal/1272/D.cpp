#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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
int ss[300001],a[300001],xj[300001];
signed main()
{
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]>a[i-1])ss[i]=ss[i-1]+1;
		else ss[i]=1;
	}
	xj[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]<a[i+1])xj[i]=xj[i+1]+1;
		else xj[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,ss[i]);
		if(a[i]>a[i-2])ans=max(ans,xj[i]+ss[i-2]);
	}
	printf("%lld\n",ans);
	return 0;
}