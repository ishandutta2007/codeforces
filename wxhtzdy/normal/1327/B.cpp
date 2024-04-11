#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> v[n];
		vector<bool> p(n, false);
		vector<bool> c(n, false);
		bool ok = 0;
		int a = -1, b = -1;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int  x;
				cin >> x;
				--x;
				v[i].push_back(x);
			}
			for (int j = 0; j < k; j++) {
				if (p[v[i][j]] == false) {
					p[v[i][j]] = true;
					c[i] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (ok || c[i]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (!p[j]) {
					a = i + 1;
					b = j + 1;
					p[j] = 1;
					ok = 1;
					break;
				}
			}
		}
		if (!ok) {
			cout << "OPTIMAL" << endl;
		} else {
			cout << "IMPROVE" << " " << a << " " << b << endl;
		}
	}
	return 0;
}