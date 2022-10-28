#include <bits/stdc++.h>
using namespace std;

const int MX = 2000;
const int MXA = 26;

int ps[MXA + 1][MX + 2];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= MXA; ++j) {
			ps[j][i] = 0;
		}
		int a;
		cin >> a;
		++ps[a][i];
	}
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= MXA; ++j) {
			ps[j][i] += ps[j][i - 1];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j <= n; ++j) {
			int mx1 = 0, mx2 = 0;
			for (int k = 1; k <= MXA; ++k) {
				mx1 = max(mx1, min(ps[k][i - 1], ps[k][n] - ps[k][j]));
				mx2 = max(mx2, ps[k][j] - ps[k][i - 1]);
			}
			ans = max(ans, mx1 * 2 + mx2);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}