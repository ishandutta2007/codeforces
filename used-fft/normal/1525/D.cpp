#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << ' ' <<
#define nl << '\n'


int dp[5001][5001];
const int INF = 1e18;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	bool a[n+1];

	for(int i=1; i<=n; ++i) fill(dp[i], dp[i]+n+1, INF), cin >> a[i];

	for(int i=1; i<=n; ++i){
		if(a[i]) break;
		fill(dp[i], dp[i]+1+n, 0);
	}

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j){
			if(a[i]){
				if(!a[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + max(i-j, j-i));
			}else{
				dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
		}
		int mn = INF;
		for(int j=0; j<=n; ++j){
			dp[i][j] = min(dp[i][j], mn);
			mn = min(dp[i][j], mn);
		}
	}
	cout << dp[n][n] nl;
}