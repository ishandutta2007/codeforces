#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int a[n], b[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i];
		}
		int p[m];
		for (int i = 0; i < m; i++) {
			cin >> p[i];
			p[i]--;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[p[j]] > a[p[j] + 1]) {
					swap(a[p[j]], a[p[j] + 1]);
				}
			}
		}
		sort(b, b + n);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}