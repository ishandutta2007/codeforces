#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		long long a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] = ((i + a[i]) % n + n) % n;
		}
		sort(a, a + n);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			ok &= a[i] == i;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}