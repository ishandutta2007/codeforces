#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt += a[i] % 2 == 1;
		}
		bool ok = false;
		int p = n - cnt;
		for (int i = 1; i <= min(cnt, k); i++) {
			if (i % 2 == 1 && i + p >= k) {
				ok = true;
				break;
			}
		}
		if (ok == true) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}