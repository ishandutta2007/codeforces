#include <bits/stdc++.h>
using namespace std;

const int MX = 1e3;
const int M = 1e9 + 7;

int grid[MX + 1][MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	memset(grid, -1, sizeof grid);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		fill(grid[i], grid[i] + a, 1);
		grid[i][a] = 0;
	}
	for (int j = 0; j < m; ++j) {
		int a;
		cin >> a;
		for (int i = 0; i < a; ++i) {
			if (grid[i][j] == 0) {
				cout << 0 << '\n';
				return false;
			}
			grid[i][j] = 1;
		}
		if (grid[a][j] == 1) {
			cout << 0 << '\n';
			return false;
		}
		grid[a][j] = 0;
	}

	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == -1) {
				ans = ans * 2 % M;
			}
		}
	}
	cout << ans << '\n';
}