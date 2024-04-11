#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k, m; cin >> n >> k >> m;
	vector<int> a(n+1, 1); a[0] = 0;
	vector<int> b;
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		a[x] = 0;
		b.push_back(x);
	}

	if ((n-m) % (k-1)) {
		cout << "NO\n"; return;
	}
	if (n == m) {
		cout << "YES\n"; return;
	}

	for (int i = 1; i <= n; i++) {
		a[i] += a[i-1];
	}

	for (int i = 1; i <= n; i++) {
		if (!binary_search(b.begin(), b.end(), i)) continue;

		int lf = a[i], rt = (n-m) - a[i];
		if (lf >= k/2 && rt >= k/2) {
			cout << "YES\n"; return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}
	
	return 0;
}