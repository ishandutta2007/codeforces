#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;

		vector<string> grid(2);
		for (auto &i : grid) cin >> i;

		while (grid[0][n - 1] == '.' && grid[1][n - 1] == '.') --n;

		vector dp(n + 1, vector<int>(4, INT_MAX));
		dp[0][0] = 0;

		for (int i = 0; i < n; ++i) {
			int level = ((grid[1][i] == '*') << 1) | (grid[0][i] == '*');
			for (int mask = 0; mask < 4; ++mask) {
				if (dp[i][mask] < INT_MAX) {
					dp[i + 1][mask | level] = min(dp[i + 1][mask | level], dp[i][mask] + __builtin_popcount(mask));
				}
			}
			if (dp[i + 1][3] < INT_MAX) {
				dp[i + 1][1] = min(dp[i + 1][1], dp[i + 1][3] + 1);
				dp[i + 1][2] = min(dp[i + 1][2], dp[i + 1][3] + 1);
			}
		}

		cout << min(dp[n][1], dp[n][2]) << "\n";
	}
}