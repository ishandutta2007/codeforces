#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			int f = l;
			if (f % (i + 1) != 0)
				f += ((i + 1) - f % (i + 1));
			a[i] = f;
		}
		if (*max_element(a.begin(), a.end()) > r) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " \n"[i == n - 1];
			}
		}
	}
}