#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int w, d;
	ll n, p;
	cin >> n >> p >> w >> d;
	for (ll i = 0; i < w && i * d <= p; ++i) {
		ll left = p - i * d;
		if (left % w == 0 && i + left / w <= n) {
			cout << left / w << ' ' << i << ' ' << n - i - left / w << '\n';
			return 0;
		}	
	}
	cout << -1 << '\n';
}