#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> l(n), s(n), c(n + m);
	for (auto& i : l) {
		cin >> i;
		--i;
	}
	for (auto& i : s) {
		cin >> i;
	}
	for (auto& i : c) {
		cin >> i;
	}

	vector<vector<int>> dp(n + m, vector<int>(n + 1, -1e9));
	for (int i = 0; i < n + m; ++i) {
		dp[i][0] = 0;
	}

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n; j; --j) {
			dp[l[i]][j] = max(dp[l[i]][j], dp[l[i]][j - 1] - s[i] + c[l[i]]);
		}
		for (int j = l[i] + 1, len = n; j < n + m; ++j, len /= 2) {
			for (int k = 0; k <= len; ++k) {
				dp[j][k / 2] = max(dp[j][k / 2], dp[j - 1][k] + k / 2 * c[j]);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n + m; ++i) {
		ans = max(ans, dp[i][1]);
	}
	cout << ans << '\n';
}