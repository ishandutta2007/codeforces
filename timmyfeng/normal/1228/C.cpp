#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 1e9 + 7;

ll ans = 1, x, n;

ll modPow(ll b, ll e) {
	if (!e) return 1;
	if (e % 2) return b * modPow(b, e - 1) % M;
	ll tmp = modPow(b, e / 2);
	return tmp * tmp % M;
}

void process(ll i) {
	ll ct = 0;
	ll k = 1;
	while (k <= n / i) {
		k *= i;
		ct += n / k;
	}
	ans = ans * modPow(i, ct) % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> x >> n;

	for (ll i = 2; i * i <= x; ++i) {
		if (x % i) continue;
		while (x % i == 0) {
			x /= i;
		}
		process(i);
	}
	if (x > 1) {
		process(x);
	}
	cout << ans << '\n';
}