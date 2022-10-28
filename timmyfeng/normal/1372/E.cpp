#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> l, r;
	vector<vector<int>> grid(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		while (k--) {
			l.push_back(0);
			r.push_back(0);
			cin >> l.back() >> r.back();
			for (int j = l.back(); j <= r.back(); ++j) {
				grid[i][j] = l.size() - 1u;
			}
		}
	}

	vector<vector<int>> dp(m + 2, vector<int>(m + 2));
	for (int len = 1; len <= m; ++len) {
		for (int i = 1; i + len - 1 <= m; ++i) {
			int j = i + len - 1;
			for (int k = i; k <= j; ++k) {
				int cnt = 0;
				for (int kk = 1; kk <= n; ++kk) {
					cnt += (l[grid[kk][k]] >= i && r[grid[kk][k]] <= j);
				}
				dp[i][j] = max(dp[i][j], dp[i][k - 1] + cnt * cnt + dp[k + 1][j]);
			}
		}
	}

	cout << dp[1][m] << "\n";
}