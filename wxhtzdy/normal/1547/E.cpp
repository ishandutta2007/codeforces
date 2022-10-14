#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(k);
		for (int i = 0; i < k; i++) {
			cin >> a[i];
			a[i] -= 1;
		}
		vector<int> t(k);
		for (int i = 0; i < k; i++) {
			cin >> t[i];
		}
		const int inf = 1e9 + 1e8;
		vector<int> pref(n, inf), suff(n, inf);
		for (int i = 0; i < k; i++) {
			pref[a[i]] = t[i] - a[i];
			suff[a[i]] = t[i] + a[i];
		}
		for (int i = 1; i < n; i++) pref[i] = min(pref[i], pref[i - 1]);
		for (int i = n - 2; i >= 0; i--) suff[i] = min(suff[i], suff[i + 1]);
		for (int i = 0; i < n; i++) {
			cout << min(pref[i] + i, suff[i] - i) << " ";
		}
		cout << '\n';
	}
	return 0;
}