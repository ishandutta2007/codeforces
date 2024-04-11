#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<double> a(n);
	vector<double> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	map<long double, int> mp;
	int ans = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (b[i] == 0) {
				cnt++;
			}
			continue;
		}
		long double x = -b[i] / a[i];
		mp[x]++;
		ans = max(ans, mp[x]);
	}
	cout << ans + cnt << '\n';
	return 0;
}