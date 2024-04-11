#include <bits/stdc++.h> 
using namespace std;

const int MX = 17;

vector<int> dp[2][2][MX + 1];
bool fan[1 << MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	while (k--) {
		int a;
		cin >> a;
		fan[a - 1] = true;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				dp[j][k][i].assign(1 << (n - i), -1);
			}
		}
	}

	for (int i = 0; i < (1 << n); i += 2) {
		dp[fan[i]][fan[i + 1]][1][i / 2] = (fan[i] || fan[i + 1]);
		dp[fan[i + 1]][fan[i]][1][i / 2] = (fan[i] || fan[i + 1]);
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < (1 << (n - i)); j += 2) {
			for (int a = 0; a < 2; ++a) {
				for (int b = 0; b < 2; ++b) {
					for (int c = 0; c < 2; ++c) {
						for (int d = 0; d < 2; ++d) {
							for (int e = 0; e < 2; ++e) {
								for (int f = 0; f < 2; ++f) {
									for (int g = 0; g < 2; ++g) {
										if (dp[a][b][i][j] == -1 || dp[c][d][i][j + 1] == -1) {
											continue;
										}

										bool win_u = e ? a : c;
										bool lose_u = e ? c : a;
										bool win_l1 = f ? b : d;
										bool win_l2 = g ? win_l1 : lose_u;

										dp[win_u][win_l2][i + 1][j / 2] = max(dp[win_u][win_l2][i + 1][j / 2],
												dp[a][b][i][j] + dp[c][d][i][j + 1] +
												(a || c) + (b || d) + (win_l1 || lose_u));
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			ans = max(ans, dp[i][j][n][0] + (i || j));
		}
	}
	cout << ans << '\n';
}