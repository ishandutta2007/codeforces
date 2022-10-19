#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7,N=255;
int c[N][N],pk[N],pk1[N],dp[N][N];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
	pk[0]=pk1[0]=1;
	for(int i=1;i<=n;i++)
	{
		pk[i]=pk[i-1]*k%mod;
		pk1[i]=pk1[i-1]*(k-1)%mod;
	}
	for(int i=0;i<n;i++)
		dp[1][i]=pk1[i]*c[n][i]%mod;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i+1][j]=(dp[i+1][j]+(dp[i][j]*pk1[j]%mod*(pk[n-j]-pk1[n-j]+mod)%mod))%mod;
			for(int k=1;k<=j;k++)
				dp[i+1][j-k]=(dp[i+1][j-k]+dp[i][j]*c[j][k]%mod*pk1[j-k]%mod*pk[n-j]%mod)%mod;
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}