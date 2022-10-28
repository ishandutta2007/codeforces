#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

vector<pair<int, int>> adj[MX][MX];

int qry(int x1, int y1, int x2, int y2) {
	if (x1 + y1 > x2 + y2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << endl;
	int res;
	cin >> res;
	return res ^ 1;
}

void add_edge(int x1, int y1, int x2, int y2) {
	adj[x1][y1].emplace_back(x2, y2);
	adj[x2][y2].emplace_back(x1, y1);
}

vector<vector<vector<vector<int>>>> calc(vector<vector<int>> col) {
	int n = col.size();
	vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n))));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < n; ++l) {
					if (col[i][j] != col[k][l])
						continue;

					if (k + l - i - j <= 1) {
						dp[i][j][k][l] = 1;
					} else {
						if (i + 1 < n && k) {
							dp[i][j][k][l] |= dp[i + 1][j][k - 1][l];
						}
						if (i + 1 < n && l) {
							dp[i][j][k][l] |= dp[i + 1][j][k][l - 1];
						}
						if (j + 1 < n && k) {
							dp[i][j][k][l] |= dp[i][j + 1][k - 1][l];
						}
						if (j + 1 < n && l) {
							dp[i][j][k][l] |= dp[i][j + 1][k][l - 1];
						}
					}
				}
			}
		}
	}
	return dp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i + 2 < n) {
				add_edge(i, j, i + 2, j);
			}
			if (j + 2 < n) {
				add_edge(i, j, i, j + 2);
			}
			if (i + 1 < n && j + 1 < n) {
				add_edge(i, j, i + 1, j + 1);
			}
		}
	}

	vector<vector<int>> col(n, vector<int>(n));
	vector<vector<bool>> vstd(n, vector<bool>(n));
	queue<pair<int, int>> que;
	col[0][0] = 1;
	que.emplace(0, 0);
	vstd[0][0] = true;
	que.emplace(0, 1);
	vstd[0][1] = true;
	que.emplace(n - 1, n - 1);
	vstd[n - 1][n - 1] = true;

	while (!que.empty()) {
		auto [r, c] = que.front();
		que.pop();
		for (auto [new_r, new_c] : adj[r][c]) {
			if (!vstd[new_r][new_c]) {
				col[new_r][new_c] = col[r][c] ^ qry(r, c, new_r, new_c);
				vstd[new_r][new_c] = true;
				que.emplace(new_r, new_c);
			}
		}
	}

	auto oth = col;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2) {
				oth[i][j] ^= 1;
			}
		}
	}

	auto dp_1 = calc(col);
	auto dp_2 = calc(oth);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < n; ++l) {
					if (k + l - i - j > 1 && dp_1[i][j][k][l] != dp_2[i][j][k][l]) {
						if (qry(i, j, k, l) ^ dp_2[i][j][k][l]) {
							swap(oth, col);
						}
						goto done;
					}
				}
			}
		}
	} done:

	cout << "!\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << col[i][j];
		}
		cout << "\n";
	}
}