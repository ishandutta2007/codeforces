#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=1e9+7;
int n,m,dp[N][N],sum[N][N],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
			dp[i][j]=(dp[i][j-1]+sum[i-1][j]+(j==2))%mod;
		for(int j=2;j<=m;j++)
			sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			int x=(dp[i][j]-dp[i-1][j]+mod)%mod;
			x=1ll*x*dp[n-i+1][j]%mod;
			x=1ll*x*(m-j+1)%mod;
			ans=(ans+x)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}