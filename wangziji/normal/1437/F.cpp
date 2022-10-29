#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[5005],dp[5005][5005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=1;j<=n;j++)
			if(a[j]<=a[i]/2) pos=j;
		for(int j=0;j<=n;j++)
			dp[i][j+1]=(dp[pos][j]+dp[i][j+1])%mod;
		int cnt=pos+1;
		for(int j=1;j<=n;j++)
			dp[i][j]=(dp[i][j-1]*(cnt-(j-1))+dp[i][j])%mod;
		for(int j=0;j<=n;j++)
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
	}
	cout << dp[n][n];
	return 0;
}