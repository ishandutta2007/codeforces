#include <bits/stdc++.h>
using namespace std;

int k[3];
int ps[3][200002];

int ct(int n, int a, int b) {
	if (a > b) return 0;
	return ps[n][b] - ps[n][a - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> k[0] >> k[1] >> k[2];
	int n = k[0] + k[1] + k[2];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < k[i]; ++j) {
			int a;
			cin >> a;
			++ps[i][a];
		}
		for (int j = 1; j <= n; ++j) {
			ps[i][j] += ps[i][j - 1];
		}
	}
	
	int mn = 0, j = 0, ans = 1e9;
	for (int i = 1; i <= n + 1; ++i) {
		if (ps[1][i - 1] - ps[0][i - 1] < mn) {
			mn = ps[1][i - 1] - ps[0][i - 1];
			j = i - 1;
		}
		ans = min(ans, ct(0, i, n) + ct(1, i, n) + ct(0, j + 1, i - 1) + ps[1][j] + ps[2][i - 1]);
	}
	cout << ans << '\n';
}