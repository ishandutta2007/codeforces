#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, x, M=1e9+7, dp[2][319][319];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x;
	if(n>m) {
		cout << 0;
		return 0;
	}
	dp[1][0][0]=1;
	for(int i=0; i<=m; ++i) {
		for(int j=0; j<=n; ++j) {
			for(int k=0; k<=n; ++k) {
				dp[i&1][j][k]=0;
				if(i!=x-1)
					dp[i&1][j][k]=(dp[i&1^1][j][k]+dp[i&1][j][k])%M;
				if(i!=x-1&&j)
					dp[i&1][j][k]=(dp[i&1^1][j-1][k+1]+dp[i&1][j][k])%M;
				if(k)
					dp[i&1][j][k]=(dp[i&1^1][j][k-1]+dp[i&1][j][k])%M;
				if(j&&k)
					dp[i&1][j][k]=(dp[i&1^1][j-1][k]+dp[i&1][j][k])%M;
			}
		}
	}
	ll ans=dp[m&1][n][0];
	for(int i=1; i<=n; ++i)
		ans=(long long)ans*i%M;
	cout << ans;
}