#include <bits/stdc++.h>
using namespace std;

int a[101];
bool p[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		memset(p, false, sizeof p);
		while (m--) {
			int _p;
			cin >> _p;
			p[_p] = true;
		}

		bool ok = true;
		for (int i = 1; i <= n; ++i) {
			int tmp = a[i];
			int j = i;
			while (j > 1 && a[j - 1] > tmp) {
				if (!p[j - 1]) {
					ok = false;
				}
				a[j] = a[j - 1];
				--j;
			}
			a[j] = tmp;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}