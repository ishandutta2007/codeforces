#include <bits/stdc++.h>
using namespace std;

const int DR[] = {1, 0, -1, 0};
const int DC[] = {0, 1, 0, -1};

void solve() {
	int n, m;
	cin >> n >> m;

	vector<array<int, 2>> bad, good;
	vector<vector<bool>> wall(n, vector<bool>(m));
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '#') {
				wall[i][j] = true;
			} else if (s[j] == 'B') {
				bad.push_back({i, j});
			} else if (s[j] == 'G') {
				good.push_back({i, j});
			}
		}
	}
	
	for (auto i : bad) {
		for (int j = 0; j < 4; ++j) {
			int ni = i[0] + DR[j];
			int nj = i[1] + DC[j];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
				wall[ni][nj] = true;
			}
		}
	}

	queue<array<int, 2>> que;
	vector<vector<bool>> vstd(n, vector<bool>(m));
	if (!wall[n - 1][m - 1]) {
		que.push({n - 1, m - 1});
		vstd[n - 1][m - 1] = true;
	}

	while (!que.empty()) {
		auto pt = que.front();
		que.pop();
		for (int j = 0; j < 4; ++j) {
			int ni = pt[0] + DR[j];
			int nj = pt[1] + DC[j];
			if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vstd[ni][nj] && !wall[ni][nj]) {
				vstd[ni][nj] = true;
				que.push({ni, nj});
			}
		}
	}

	bool ok = true;
	for (auto i : good) {
		ok &= vstd[i[0]][i[1]];
	}
	cout << (ok ? "Yes" : "No") << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}