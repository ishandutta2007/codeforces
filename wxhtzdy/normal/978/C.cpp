#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	long long a[n], pref[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == 0) {
			pref[i] = a[i];
		} else {
			pref[i] = pref[i - 1] + a[i];
		}
	}
	for (int i = 0; i < m; i++) {
		long long k;
		cin >> k;
		int bot = 0, top = n - 1, j = 0;
		while (bot <= top) {
			int mid = (bot + top) >> 1;
			if (pref[mid] < k) {
				bot = mid + 1;
			} else {
				top = mid - 1;
				j = mid;
			}
		}
		if (k == pref[n - 1]) {
			cout << n << " " << a[n - 1] << '\n';
			continue;
 		}
		cout << j + 1 << " " << k - pref[j] + a[j] << '\n';
	}
	return 0;
}