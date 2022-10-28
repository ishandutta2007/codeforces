#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i].first;
			sum += a[i].first;
			a[i].second = i + 1;
		}
		sort(a.begin(), a.end());
		if (m < n || n == 2) {
			cout << -1 << '\n';
			continue;
		}
		cout << sum * 2 + (m - n) * (a[1].first + a[0].first) << '\n';
		for (int i = 1; i <= n; ++i) {
			cout << i << ' ' << (i == n ? 1 : i + 1) << '\n';
		}
		for (int i = 0; i < m - n; ++i) {
			cout << a[0].second << ' ' << a[1].second << '\n';
		}
	}
}