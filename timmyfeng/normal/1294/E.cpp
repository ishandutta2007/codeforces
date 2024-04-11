#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

int cyc[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	for (int c = 1; c <= m; ++c) {
		iota(cyc, cyc + n, n);
		for (int i = 1; i <= n; ++i) {
			if (mat[i][c] % m != c % m || mat[i][c] > n * m) continue;
			--cyc[(i - ((mat[i][c] - 1) / m + 1) + n) % n];
		}
		ans += *min_element(cyc, cyc + n);
	}
	cout << ans << '\n';
}