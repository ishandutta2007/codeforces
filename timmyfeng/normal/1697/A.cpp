#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t; cin >> t;

	while (t--) {
		int n, m; cin >> n >> m;

		for (int i = 0; i < n; ++i) {
			int a; cin >> a;
			m -= a;
		}

		cout << max(0, -m) << "\n";
	}
}