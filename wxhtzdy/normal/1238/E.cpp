// join this fan club https://codeforces.com/ratings/organization/30051

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<vector<int>> cnt(m, vector<int>(m));
	for (int i = 0; i + 1 < n; i++) {
		int x = s[i] - 'a';
		int y = s[i + 1] - 'a';
		cnt[x][y] += 1;
		cnt[y][x] += 1;
	}
	vector<int> dp(1 << m, 1e6);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		int pos = 0;
		for (int j = 0; j < m; j++) {
			if (mask & (1 << j)) {
				pos += 1;
			}
		}
		for (int i = 0; i < m; i++) {
			if (mask & (1 << i)) {
				continue;
			}
			int ft = 0;
			for (int j = 0; j < m; j++) {
				if (i == j) {
					continue;
				}
				if (mask & (1 << j)) {
					ft += cnt[i][j] * pos;
				} else {
					ft -= cnt[i][j] * pos;
				}
			}
			dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + ft);
		}
	}
	cout << dp[(1 << m) - 1] << '\n';
	return 0;
}