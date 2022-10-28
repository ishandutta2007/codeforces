#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	int q;
	cin >> n >> q;
	while (q--) {
		ll x, y;
		cin >> x >> y;
		if (n % 2) {
			ll ndx = (x - 1) * n + y - 1;
			if (ndx % 2) {
				cout << ndx / 2 + n * n / 2 + 2 << '\n'; 
			} else {
				cout << ndx / 2 + 1 << '\n';
			}
		} else {
			if ((x % 2) ^ (y % 2)) {
				cout << n * n / 2 + (x - 1) * n / 2 + (y + 1) / 2 << '\n';
			} else {
				cout << (x - 1) * n / 2 + (y + 1) / 2 << '\n';
			}
		}
	}
}