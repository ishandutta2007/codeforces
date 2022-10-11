#include <iostream>

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

int main() {
	ll n;
	std::cin >> n;
	std::cout << (MOD + fexp(27, n) - fexp(7, n)) % MOD << '\n';
}