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
int a[10005],b[10005],dp[5005][5005];
signed main()
{
	int n,tans=0,ans;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		tans+=a[i]*b[i];
	}
	for(int i=1;i<=n;i++)dp[i][i]=tans;
	for(int i=1;i<=n-1;i++)
	{
		dp[i][i+1]=tans+a[i]*b[i+1]+a[i+1]*b[i]-a[i]*b[i]-a[i+1]*b[i+1];
	}
	for(int len=3;len<=n;len++)
	{
		for(int l=1;l<=n-len+1;l++)
		{
			int r=l+len-1;
			dp[l][r]=dp[l+1][r-1]+a[l]*b[r]+a[r]*b[l]-a[l]*b[l]-a[r]*b[r];
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}