#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i ){
		cin >> a[i] >> b[i];
	}

	vector<vector<ll>> dp(3, vector<ll>(n));
	dp[1][0] = b[0];
	dp[2][0] = 2 * b[0];
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= 2; ++j) {
			dp[j][i] = 1e18;
			for (int k = 0; k <= 2; ++k) {
				if (a[i - 1] + k != a[i] + j) {
					dp[j][i] = min(dp[j][i], dp[k][i - 1] + b[i] * j);
				}
			}
		}
	}
	cout << min({dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]}) << '\n';
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