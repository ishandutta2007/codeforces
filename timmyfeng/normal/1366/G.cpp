#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e4 + 1;
const int INF = 0x3f3f3f3f;

int jump[MX], dp[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();

	for (int i = 0; i < n; ++i) {
		if (s[i] == '.') {
			jump[i] = i;
			continue;
		}
		int cur = 0;
		int j = i;
		do {
			cur += s[j++] == '.' ? -1 : 1;
		} while (j < n && cur);
		jump[i] = cur ? i : j;
	}

	memset(dp, INF, sizeof dp);
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (dp[i][j] == INF)
				continue;

			if (j < m && s[i] == t[j]) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
			}
			if (j && s[i] == '.') {
				dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
			}
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[jump[i]][j] = min(dp[jump[i]][j], dp[i][j]);
		}
	}
	cout << dp[n][m] << '\n';
}