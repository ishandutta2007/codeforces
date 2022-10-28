#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int odds = (n + 1) / 2;
	vector<int> g(n);
	for (auto &i : g) {
		cin >> i;
		odds -= i % 2;
	}

	vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(odds + 1));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= odds; j++) {
			if (i == 0) {
				if (j) {
					dp[i][j] = { 100, 100 };
				}
			} else if (g[i - 1]) {
				if (g[i - 1] % 2) {
					dp[i][j].first = 100;
					dp[i][j].second = min(dp[i - 1][j].first + 1, dp[i - 1][j].second);
				} else {
					dp[i][j].second = 100;
					dp[i][j].first = min(dp[i - 1][j].first, dp[i - 1][j].second + 1);
				}
			}
			else {
				dp[i][j].first = min(dp[i - 1][j].first, dp[i - 1][j].second + 1);
				if (j) {
					dp[i][j].second = min(dp[i - 1][j - 1].second, dp[i - 1][j - 1].first + 1);
				} else {
					dp[i][j].second = 100;
				}
			}
		}
	}
	cout << min(dp[n][odds].first, dp[n][odds].second) << "\n";
}