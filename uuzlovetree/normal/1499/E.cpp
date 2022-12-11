#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
const int mod = 998244353;
char a[maxn],b[maxn];
int n,m;
int dp[maxn][maxn][2];
int f[maxn],g[maxn];
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;++i)
	{
		f[i]=1;
		for(int j=i-1;j>=1;--j)if(a[j+1]!=a[j])f[i]++;else break;
	}
	for(int i=1;i<=m;++i)
	{
		g[i]=1;
		for(int j=i-1;j>=1;--j)if(b[j+1]!=b[j])g[i]++;else break;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(a[i]!=b[j])dp[i][j][0]=g[j],dp[i][j][1]=f[i];
			else dp[i][j][0]=dp[i][j][1]=0;
		}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(a[i]!=a[i+1])
			{
				dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][0])%mod;
			}
			if(a[i]!=b[j+1])
			{
				dp[i][j+1][1]=(dp[i][j+1][1]+dp[i][j][0])%mod;
			}
			if(b[j]!=a[i+1])
			{
				dp[i+1][j][0]=(dp[i+1][j][0]+dp[i][j][1])%mod;
			}
			if(b[j]!=b[j+1])
			{
				dp[i][j+1][1]=(dp[i][j+1][1]+dp[i][j][1])%mod;
			}
			ans=(ans+dp[i][j][0])%mod;
			ans=(ans+dp[i][j][1])%mod;
		}
	}
	printf("%d\n",ans);
}