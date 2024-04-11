#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	vector<vector<ll>> dp(2, vector<ll>(n + 1, 1e18));
	dp[0][0] = b;
	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] != '1' && (i >= n || s[i] != '1')) {
			dp[0][i] = min({dp[0][i], dp[0][i - 1] + a + b, dp[1][i - 1] + 2 * a + b});
		}
		dp[1][i] = min({dp[1][i], dp[0][i - 1] + 2 * a + 2 * b, dp[1][i - 1] + a + 2 * b});
		//cout << i << ' ' << dp[0][i] << ' ' << dp[1][i] << '\n';
	}
	cout << dp[0][n] << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}