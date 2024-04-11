#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> cnt(n);
	vector<int> best(n, n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		++cnt[a];
		best[a] = min(best[a], (b - a + n) % n);
	}

	for (int i = 0; i < n; ++i) {
		int ans = 0;
		for (int j = 0; j < n; ++j) {
			if (cnt[(i + j) % n]) {
				ans = max(ans, j + (cnt[(i + j) % n] - 1) * n + best[(i + j) % n]);
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}