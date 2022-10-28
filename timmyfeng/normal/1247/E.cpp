#include <bits/stdc++.h>
using namespace std;
const int MX = 2e3;
const int MOD = 1e9 + 7;
int dpr[MX][MX], dpd[MX][MX], bel[MX][MX], rig[MX][MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (auto& i : grid) {
		cin >> i;
	}
	if (grid[0][0] == 'R') {
		cout << 0 << '\n';
		return 0;
	} else if (m == 1 && n == 1) {
		cout << 1 << '\n';
		return 0;	
	}
	
	for (int i = n - 1; ~i; --i) {
		for (int j = m - 1; ~j; --j) {
			if (i + 1 < n) {
				bel[i][j] = (grid[i + 1][j] == 'R') + bel[i + 1][j];
			}
			if (j + 1 < m) {
				rig[i][j] = (grid[i][j + 1] == 'R') + rig[i][j + 1];
			}
		}
	}

	for (int i = n - 1; ~i; --i) {
		for (int j = m - 1; ~j; --j) {
			if (i == n - 1 && j == m - 1) {
				dpr[i][j] = dpd[i][j] = 1;
				continue;
			}
			if (i == n - 1) {
				dpd[i][j] = 0;
			} else {
				if (i == n - 2 && j == m - 1) {
					dpd[i][j] = 1;
				} else {
					dpd[i][j] = (dpd[i + 1][j] + dpr[i + 1][j]) % MOD;
				}
				if (grid[i + 1][j] == 'R') {
					((dpd[i][j] -= dpr[n - bel[i][j]][j]) += MOD) %= MOD;
				}
			}
			if (j == m - 1) {
				dpr[i][j] = 0;
			} else {
				if (j == m - 2 && i == n - 1) {
					dpr[i][j] = 1;
				} else {
					dpr[i][j] = (dpr[i][j + 1] + dpd[i][j + 1]) % MOD;
				}
				if (grid[i][j + 1] == 'R') {
					((dpr[i][j] -= dpd[i][m - rig[i][j]]) += MOD) %= MOD;
				}
			}
		}
	}
	cout << (dpr[0][0] + dpd[0][0]) % MOD << '\n';
}