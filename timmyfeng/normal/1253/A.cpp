#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& i : a)
			cin >> i;
		for (auto& i : b)
			cin >> i;
		
		int d = 0;
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				if (!d) {
					d = b[i] - a[i];
					if (d < 0) {
						ok = false;
					}
				} else {
					if (d != b[i] - a[i]) {
						ok = false;
					}
				}
			} else {
				if (d) {
					d = 1e9;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}