#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = 1e9 + 7;

ll fact[251];

ll modPow(ll b, ll e) {
	if (!e) return 1;
	if (e % 2) return b * modPow(b, e - 1) % M;
	ll tmp = modPow(b, e / 2);
	return tmp * tmp % M;
}

ll comb(ll n, ll k) {
	return fact[n] * modPow(fact[k], M - 2) % M * modPow(fact[n - k], M - 2) % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = i * fact[i - 1] % M;
	}
	for (ll s = 0; s < n; ++s) {
		ll res = comb(n, s) * modPow(k - 1, s * n) % M * modPow((modPow(k, n - s) - modPow(k - 1, n - s) + M) % M, n) % M;
		if (s % 2) {
			ans = (ans - res + M) % M;
		} else {
			ans = (ans + res) % M;
		}
	}
	cout << ans << '\n';
}