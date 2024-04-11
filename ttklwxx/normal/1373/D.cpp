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
int a[300001];
signed main()
{
	int t,n,ans,tans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		tans=0;
		for(int i=2;i<=n-1;i+=2)
		{
			ans=max(ans,0LL)+a[i]-a[i+1];
			tans=max(tans,ans);
		}
		ans=0;
		for(int i=2;i<=n;i+=2)
		{
			ans=max(ans,0LL)+a[i]-a[i-1];
			tans=max(tans,ans);
		}
		for(int i=1;i<=n;i+=2)tans+=a[i];
		printf("%lld\n",tans);
	}
	return 0;
}