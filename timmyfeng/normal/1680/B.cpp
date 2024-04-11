#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t; cin>> t;

	while (t--) {
		int n, m; cin >> n >> m;

		vector<string> grid(n);
		for (auto &i : grid) cin >> i;

		int x = -1, y = -1;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 'R') {
					if (x == -1) x = i, y = j;
					else ok &= i >= x && j >= y;
				}
			}
		}

		cout << (ok ? "YES" : "NO") << "\n";
	}
}