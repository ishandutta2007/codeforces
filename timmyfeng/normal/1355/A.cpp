#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll a, k;
		cin >> a >> k;
		for (ll i = 1; i < k; ++i) {
			ll mn = 10, mx = 0, tmp = a;
			while (tmp) {
				mn = min(mn, tmp % 10);
				mx = max(mx, tmp % 10);
				tmp /= 10;
			}
			if (!mn)
				break;
			a += mn * mx;
		}
		cout << a << '\n';
	}
}