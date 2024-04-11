#include <bits/stdc++.h> 
using namespace std;

const int MX = 100 + 1;
const int W = 1e4;
const int INF = 0x3f3f3f3f;
const int DR[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int DC[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int dist[3 * MX][3 * MX], dp[MX][3], row[MX], col[MX], n;

int getId(int i, int j, int k) {
	return i * n + j + k * n * n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			cin >> a;
			row[a] = i;
			col[a] = j;
		}
	}

	memset(dist, INF, sizeof dist);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					dist[getId(i, j, k)][getId(i, j, l)] = W + 1;
				}
				dist[getId(i, j, k)][getId(i, j, k)] = 0;
			}

			for (int k = 0; k < 8; ++k) {
				int ni = i + DR[k];
				int nj = j + DC[k];
				if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
					dist[getId(i, j, 0)][getId(ni, nj, 0)] = W;
				}
			}

			for (int k = 0; k < n; ++k) {
				if (k != j) {
					dist[getId(i, j, 1)][getId(i, k, 1)] = W;
				}
				if (k != i) {
					dist[getId(i, j, 1)][getId(k, j, 1)] = W;
				}
			}

			for (int k = 1; k < n; ++k) {
				for (int x = 0; x < 2; ++x) {
					for (int y = 0; y < 2; ++y) {
						int ni = x ? i - k : i + k;
						int nj = y ? j - k : j + k;
						if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
							dist[getId(i, j, 2)][getId(ni, nj, 2)] = W;
						}
					}
				}
			}
		}
	}

	for (int k = 0; k < 3 * n * n; ++k) {
		for (int i = 0; i < 3 * n * n; ++i) {
			for (int j = 0; j < 3 * n * n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	memset(dp, INF, sizeof dp);
	dp[1][0] = dp[1][1] = dp[1][2] = 0;
	for (int i = 2; i <= n * n; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				dp[i][j] = min(dp[i][j], 
						dp[i - 1][k] + dist[getId(row[i - 1], col[i - 1], k)][getId(row[i], col[i], j)]);
			}
		}
	}

	int ans = min({dp[n * n][0], dp[n * n][1], dp[n * n][2]});
	cout << ans / W << ' ' << ans % W << '\n';
}