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
int dp[2005][2005],a[2005];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-1121131433448687LL;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=0;
		for(int j=0;j<=i;j++)
		{
			if(dp[i-1][j]>=0)dp[i][j+1]=max(dp[i-1][j+1],dp[i-1][j]+a[i]);
			else dp[i][j+1]=dp[i-1][j+1];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(dp[n][i]>=0)ans=max(ans,i);
	printf("%lld\n",ans);
	return 0;
}