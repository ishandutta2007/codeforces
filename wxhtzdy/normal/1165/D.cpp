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
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long ans = a[0] * a.back();
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (ans % a[i] != 0) {
				ok = false;
			}
		}
		vector<int> d;
		for (int i = 2; i <= sqrt(ans); i++) {
			if (ans % i == 0) {
				d.push_back(i);
				if ((long long) i * i != ans) {
					d.push_back(ans / i);
				} 
			}
		}
		if ((int) d.size() != n) {
			ok = false;
		} else {
			sort(d.begin(), d.end());
			for (int i = 0; i < n; i++) {
				if (d[i] != a[i]) {
					ok = false;
				}
			}
		}
		cout << (ok ? ans : -1) << '\n';
	}
	return 0;
}