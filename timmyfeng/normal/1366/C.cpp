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
		vector<vector<int>> a(n, vector<int>(m));
		for (auto& i : a) {
			for (auto& j : i) {
				cin >> j;
			}
		}

		int ans = 0;
		for (int i = 0; i < (n + m) / 2; ++i) {
			if ((n + m) % 2 == 0 && i == (n + m) / 2 - 1)
				continue;
			int one = 0;
			int zero = 0;
			for (int r = 0; r < n; ++r) {
				int c = i - r;
				if (c < 0 || c >= m)
					continue;
				one += a[r][c];
				zero += !a[r][c];
			}
			for (int r = 0; r < n; ++r) {
				int c = n + m - 2 - i - r;
				if (c < 0 || c >= m)
					continue;
				one += a[r][c];
				zero += !a[r][c];
			}
			ans += min(one, zero);
		}
		cout << ans << '\n';
	}
}