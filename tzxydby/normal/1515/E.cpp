#include<bits/stdc++.h>
using namespace std;
const int N=805;
int n,mod,dp[N][N],ans,pw[N],c[N][N];
int main()
{
	scanf("%d%d",&n,&mod);
	pw[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2%mod;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=n;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	dp[0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(!dp[i][j])
				continue;
			for(int k=1;k<=n;k++)
				if(i+k+1<=n+1)
					dp[i+k+1][j+k]=(dp[i+k+1][j+k]+1ll*dp[i][j]*pw[k-1]%mod*c[j+k][k]%mod)%mod;
		}
	}
	for(int j=0;j<=n;j++)
		ans=(ans+dp[n+1][j]%mod)%mod;
	printf("%d\n",ans);
	return 0;
}