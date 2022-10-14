#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		string a[n];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '.') {
					cnt++;
				}
			}
		}
		if (x * 2 <= y) {
			cout << cnt * x << endl;
			continue;
		}
		long long ans = 0;
		bool was[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				was[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (was[i][j] == true || a[i][j] == '*') {
					continue;
				}
				if (j == m - 1 || a[i][j] != a[i][j + 1]) {
					ans += x;
					was[i][j] = true;
				} else {
					ans += y;
					was[i][j] = true;
					was[i][j + 1] = true;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;	
}