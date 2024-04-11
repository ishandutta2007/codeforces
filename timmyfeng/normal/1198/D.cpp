#include <bits/stdc++.h>
using namespace std;

const int MX = 52;

int dp[MX][MX][MX][MX];
int pre_sum[MX][MX];
string grid[MX];

int qry_sum(int i1, int j1, int i2, int j2) {
	return pre_sum[i2][j2] - pre_sum[i1 - 1][j2] - pre_sum[i2][j1 - 1] + pre_sum[i1 - 1][j1 - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pre_sum[i][j] = (grid[i - 1][j - 1] == '#');
			pre_sum[i][j] += pre_sum[i - 1][j];
			pre_sum[i][j] += pre_sum[i][j - 1];
			pre_sum[i][j] -= pre_sum[i - 1][j - 1];
		}
	}

	for (int i1 = n; i1; --i1) {
		for (int j1 = n; j1; --j1) {
			for (int i2 = i1; i2 <= n; ++i2) {
				for (int j2 = j1; j2 <= n; ++j2) {
					dp[i1][j1][i2][j2] = max(i2 - i1 + 1, j2 - j1 + 1);

					if (!qry_sum(i1, j1, i2, j2)) {
						dp[i1][j1][i2][j2] = 0;
					}

					for (int i = i1; i <= i2; ++i) {
						if (!qry_sum(i, j1, i, j2)) {
							dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2],
									dp[i1][j1][i - 1][j2] + dp[i + 1][j1][i2][j2]);
						}
					}

					for (int j = j1; j <= j2; ++j) {
						if (!qry_sum(i1, j, i2, j)) {
							dp[i1][j1][i2][j2] = min(dp[i1][j1][i2][j2],
									dp[i1][j1][i2][j - 1] + dp[i1][j + 1][i2][j2]);
						}
					}
				}
			}
		}
	}

	cout << dp[1][1][n][n] << "\n";
}