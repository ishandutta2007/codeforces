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
		ll ans = 0;
		for (ll i = 0; i * 2 < n; ++i) {
			ans += 8 * i * i;
		}
		cout << ans << '\n';
	}
}