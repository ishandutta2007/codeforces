#include <bits/stdc++.h>
using namespace std;

int dp[1000001][5][3];
int cnt[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++cnt[a];
	}

	memset(dp, -1, sizeof dp);
	dp[0][0][0] = 0;

	for (int i = 1; i <= m; ++i) {
		for (int j = 4; j >= 0; --j) {
			for (int k = 2; k >= 0; --k) {
				if (j < 4) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k]);
				}
				if (k < 2) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k + 1]);
				}
				for (int l = 0; l <= 2 && cnt[i] - j - l >= 0; ++l) {
					if (dp[i - 1][k + l][l] != -1) {
						dp[i][j][k] = max(dp[i][j][k], (cnt[i] - j - l) / 3 + l + dp[i - 1][k + l][l]);	
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 4; ++i) {
		for (int j = 0; j <= 2; ++j) {
			ans = max(ans, dp[m][i][j]);
		}
	}
	cout << ans << "\n";
}