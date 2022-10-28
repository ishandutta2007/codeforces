#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e3 + 1;
const int MXQ = 1e5 + 1;
const int DR[] = {0, -1, 0, 1};
const int DC[] = {1, 0, -1, 0};

int t[MX][MX], n, m;
vector<string> grid;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> m >> q;
	grid.resize(n);
	for (auto& i : grid) {
		cin >> i;
	}

	queue<pair<int, int>> que;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			t[i][j] = -1;
			for (int k = 0; k < 4; ++k) {
				int ni = i + DR[k];
				int nj = j + DC[k];
				if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[i][j] == grid[ni][nj]) {
					t[i][j] = 0;
					que.emplace(i, j);
					break;
				}
			}
		}
	}

	while (!que.empty()) {
		auto [i, j] = que.front();
		que.pop();
		for (int k = 0; k < 4; ++k) {
			int ni = i + DR[k];
			int nj = j + DC[k];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && t[ni][nj] == -1) {
				t[ni][nj] = t[i][j] + 1;
				que.emplace(ni, nj);
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		int r, c;
		ll p;
		cin >> r >> c >> p;
		r--;
		c--;
		if (t[r][c] == -1 || p < t[r][c]) {
			cout << grid[r][c] << '\n';
		} else if ((p - t[r][c]) % 2) {
			cout << char('0' + '1' - grid[r][c]) << '\n';
		} else {
			cout << grid[r][c] << '\n';
		}
	}
}