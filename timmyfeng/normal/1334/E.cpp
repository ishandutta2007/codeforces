#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = (119 << 23) + 1;

ll fact[100], invFact[100];
map<ll, ll> memo;

ll solve(ll n) {
	if (memo.count(n)) return memo[n];
	ll ans = 0, m = n;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i) continue;
		while (n % i == 0) {
			n /= i;
		}
		ans = (ans + solve(m / i)) % M;
	}
	if (n > 1) {
		ans = (ans + solve(m / n)) % M;
	}
	return memo[m] = ans % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll d, q;
	cin >> d >> q;

	fact[0] = 1;
	for (int i = 1; i < 100; ++i) {
		fact[i] = i * fact[i - 1] % M;
	}
	invFact[0] = invFact[1] = 1;
	for (int i = 2; i < 100; ++i) {
		invFact[i] = (M - (M / i) * invFact[M % i] % M) % M;
	}
	for (int i = 1; i < 100; ++i) {
		invFact[i] = invFact[i] * invFact[i - 1] % M;
	}

	memo[1] = 1;
	while (q--) {
		ll v, u;
		cin >> v >> u;
		cout << solve(v / __gcd(v, u)) * solve(u / __gcd(v, u)) % M << '\n';
	}
}