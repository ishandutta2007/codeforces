#include <bits/stdc++.h> 
using namespace std;

const int MX = 500;
const int LOG_N = 10;

int pre_sum[4][MX][MX], sparse[LOG_N][LOG_N][MX][MX];

int qry_sum(int col, int a, int b, int c, int d) {
	int res = pre_sum[col][c][d];
	if (a) {
		res -= pre_sum[col][a - 1][d];
	}
	if (b) {
		res -= pre_sum[col][c][b - 1];
	}
	if (a && b) {
		res += pre_sum[col][a - 1][b - 1];
	}
	return res;
}

int qry_mx(int a, int b, int c, int d) {
	int log_r = 31 - __builtin_clz(c - a + 1);
	int log_c = 31 - __builtin_clz(d - b + 1);
	return max({
			sparse[log_r][log_c][a][b],
			sparse[log_r][log_c][c + 1 - (1 << log_r)][b],
			sparse[log_r][log_c][a][d + 1 - (1 << log_c)],
			sparse[log_r][log_c][c + 1 - (1 << log_r)][d + 1 - (1 << log_c)]
	});
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == 'R') {
				++pre_sum[0][i][j];
			} else if (s[j] == 'G') {
				++pre_sum[1][i][j];
			} else if (s[j] == 'Y') {
				++pre_sum[2][i][j];
			} else {
				++pre_sum[3][i][j];
			}
		}
	}

	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (i) {
					pre_sum[k][i][j] += pre_sum[k][i - 1][j];
				}
				if (j) {
					pre_sum[k][i][j] += pre_sum[k][i][j - 1];
				}
				if (i && j) {
					pre_sum[k][i][j] -= pre_sum[k][i - 1][j - 1];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int lb = 0;
			int rb = min({i + 1, j + 1, n - 1 - i, m - 1 - j});
			while (lb < rb) {
				int mb = (lb + rb + 1) / 2;
				if (qry_sum(0, i - mb + 1, j - mb + 1, i, j) == mb * mb &&
						qry_sum(1, i - mb + 1, j + 1, i, j + mb) == mb * mb &&
						qry_sum(2, i + 1, j - mb + 1, i + mb, j) == mb * mb &&
						qry_sum(3, i + 1, j + 1, i + mb, j + mb) == mb * mb) {
					lb = mb;
				} else {
					rb = mb - 1;
				}
			}
			sparse[0][0][i][j] = lb;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int k = 1; (1 << k) < 2 * m; ++k) {
			int len = 1 << (k - 1);
			for (int j = 0; j + len < m; ++j) {
				sparse[0][k][i][j] = max(sparse[0][k - 1][i][j], sparse[0][k - 1][i][j + len]);
			}
		}
	}

	for (int k = 0; (1 << k) < 2 * m; ++k) {
		int len_c = k ? 1 << (k - 1) : 0;
		for (int j = 0; j + len_c < m; ++j) {
			for (int l = 1; (1 << l) < 2 * n; ++l) {
				int len_r = 1 << (l - 1);
				for (int i = 0; i + len_r < n; ++i) {
					sparse[l][k][i][j] = max(sparse[l - 1][k][i][j], sparse[l - 1][k][i + len_r][j]);
				}
			}
		}
	}

	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		int lb = 0;
		int rb = min((r2 - r1 + 1) / 2, (c2 - c1 + 1) / 2);
		while (lb < rb) {
			int mb = (lb + rb + 1) / 2;
			if (qry_mx(r1 + mb - 2, c1 + mb - 2, r2 - mb - 1, c2 - mb - 1) >= mb) {
				lb = mb;
			} else {
				rb = mb - 1;
			}
		}
		cout << 4 * lb * lb << '\n';
	}
}