#include <iostream>
#define int long long
#define mod 998244353
using namespace std;
int dp[2005][4005],a[2005];
signed main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	a[n+1]=a[1];
	dp[0][2001]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			for(int j=1;j<=4002;j++)
				dp[i][j]=dp[i-1][j]*k%mod;
		}
		else
		{
			for(int j=1;j<=4002;j++)
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*(k-2)+dp[i-1][j+1],dp[i][j]%=mod;
		}
	}
	int ans=0;
	for(int i=2002;i<=4002;i++)
	{
		ans+=dp[n][i];
		ans%=mod;
	}
	cout << ans;
	return 0;
}