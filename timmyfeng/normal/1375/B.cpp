#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m));
		for (auto& i : grid) {
			for (auto& j : i) {
				cin >> j;
			}
		}

		bool ok = true;
		vector<vector<int>> ans(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
					ans[i][j] = 2;
				} else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					ans[i][j] = 3;
				} else {
					ans[i][j] = 4;
				}
				ok &= ans[i][j] >= grid[i][j];
			}
		}

		if (ok) {
			cout << "YES\n";
			for (auto& i : ans) {
				for (auto j : i) {
					cout << j << " ";
				}
				cout << "\n";
			}
		} else {
			cout << "NO\n";
		}
	}
}