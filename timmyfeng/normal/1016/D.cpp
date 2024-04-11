#include <bits/stdc++.h>
using namespace std;

const int MX = 1e2;

int a[MX], b[MX], ans[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int j = 0; j < m; ++j) {
		cin >> b[j];
	}

	for (int k = 0; k < 30; ++k) {
		vector<int> row, col;
		for (int i = 0; i < n; ++i) {
			if (a[i] & (1 << k)) {
				row.push_back(i);
			}
		}
		for (int i = 0; i < m; ++i) {
			if (b[i] & (1 << k)) {
				col.push_back(i);
			}
		}

		int sz_r = row.size();
		int sz_c = col.size();
		if (sz_r % 2 != sz_c % 2) {
			cout << "NO" << '\n';
			return 0;
		}

		for (int i = 0; i < sz_r && i < sz_c; ++i) {
			ans[row[i]][col[i]] ^= 1 << k;
		}
		
		if (sz_r > sz_c) {
			for (int i = sz_c; i < sz_r; ++i) {
				ans[row[i]][0] ^= 1 << k;
			}
		} else {
			for (int i = sz_r; i < sz_c; ++i) {
				ans[0][col[i]] ^= 1 << k;
			}
		}
	}

	cout << "YES" << '\n';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}