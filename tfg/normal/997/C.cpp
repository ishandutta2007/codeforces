#include <iostream>
#include <vector>

typedef long long ll;

const int MOD = 998244353;
const int me = 21;
const int ms = 1 << me;

ll fexp(ll x, ll e) {
	ll ans = 1;
	x %= MOD;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll fat[ms], ifat[ms];
ll comb(int n, int a) {
	if(a < 0 || a > n) return 0;
	return (ll) fat[n] * ifat[a] % MOD * ifat[n - a] % MOD;
}

int main() {
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = (ll) fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	ll n1 = fexp(3, MOD - 2);
	for(int i = 1; i <= n; i++) {
		ans = (ans + 2 * fexp(3, (ll) n * (n - i) % (MOD - 1) + i) % MOD * fexp(MOD - 1, i + 1) % MOD * comb(n, i) % MOD) % MOD;
		ll n2 = fexp(n1, n - i);
		ll n3 = (fexp(n2 + MOD - 1, n) + (n % 2 == 0 ? MOD - 1 : 1)) % MOD;
		n3 = n3 * fexp(MOD - 1, i + n + 1) % MOD;
		//std::cout << n33 << ", " << n3 << std::endl;
		ll n4 = comb(n, i) * fexp(3, ((ll) n * n + 1 - (ll) n * i) % (MOD - 1)) % MOD * n3 % MOD;
		//std::cout << "for " << i << ", got " << n4 << std::endl;
		ans = (ans + n4) % MOD;
	}
	std::cout << ans << std::endl;
}