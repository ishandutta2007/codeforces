#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> grid(n);
		for (auto& i : grid) {
			cin >> i;
		}

		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0;  j < n - 1; ++j) {
				if (grid[i][j] == '1' && grid[i + 1][j] != '1' && grid[i][j + 1] != '1') {
					ok = false;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}