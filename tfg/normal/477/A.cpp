#include <iostream>

typedef long long ll;

const ll MOD = 1e9 + 7;

ll pairs(ll x) {
	x %= MOD;
	return (x * (x + 1) / 2) % MOD;
}

int main() {
	ll a, b;
	std::cin >> a >> b;
	ll ans = 0;
	for(int i = 1; i < b; i++) {
		ll start = 1;
		ll end = a + 1;
		// i * b + i + 2 * i * b + i + 3 * b + i ...
		// (pairs(end - 1) - pairs(start - 1)) * b + (end - start)
		ans = (ans + (pairs(end - 1) - pairs(start - 1)) * b % MOD * i % MOD + (end - start) % MOD * i) % MOD;
	}
	std::cout << (ans + MOD) % MOD << '\n';
}