#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e3 + 1;

bitset<MX> vstd[MX];
string grid[MX];
int n, m;

void dfs(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '.' || vstd[i][j])
		return;
	vstd[i][j] = true;
	dfs(i + 1, j);
	dfs(i - 1, j);
	dfs(i, j + 1);
	dfs(i, j - 1);
}

bool proc(string s) {
	int res = 0;
	char prev = '.';
	for (auto i : s) {
		if (i == '#') {
			if (prev == '.') {
				++res;
			}
		}
		prev = i;
	}
	if (res > 1) {
		cout << -1 << '\n';
		exit(0);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}

	bool extr = false;
	for (int i = 0; i < n; ++i) {
		extr |= !proc(grid[i]);
	}

	bool extc = false;
	for (int j = 0; j < m; ++j) {
		string col = "";
		for (int i = 0; i < n; ++i) {
			col += grid[i][j];
		}
		extc |= !proc(col);
	}

	if (extr != extc) {
		cout << -1 << '\n';
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '#' && !vstd[i][j]) {
				++ans;
				dfs(i, j);
			}
		}
	}
	cout << ans << '\n';
}