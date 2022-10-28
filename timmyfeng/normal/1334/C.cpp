#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i] >> b[i];
		}

		ll ans = 0, mn = 1e18;
		for (int i = 0; i < n; ++i) {
			ll c = max(0LL, a[(i + 1) % n] - b[i]);
			mn = min(mn, a[(i + 1) % n] - c);
			ans += c;
		}
		cout << ans + mn << '\n';
	}
}