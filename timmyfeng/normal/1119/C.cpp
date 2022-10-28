#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (auto& i : a) {
		for (auto& j : i) {
			cin >> j;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int b;
			cin >> b;
			a[i][j] ^= b;
		}
	}

	bool ok = true;
	for (int i = 0; i < n - 1; ++i) {
		if (count(a[i].begin(), a[i].end(), 1) % 2) {
			ok = false;
			break;
		}
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) {
				a[i][j] ^= 1;
				a[i + 1][j] ^= 1;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j]) {
				ok = false;
			}
		}
	}

	cout << (ok ? "Yes" : "No") << "\n";
}