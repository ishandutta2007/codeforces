#include <iostream>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 100100;

ll fexp(ll x, ll e) {
	x %= MOD;
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

ll a[ms], b[ms];

int main() {
	ll n, m;
	std::cin >> n >> m;
	ll equal = 1;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	ll pp = fexp((ll)m * m % MOD, MOD - 2);
	ll pe = pp * m % MOD;
	ll pg = (m * (m - 1) / 2) % MOD * pp % MOD;
	ll inv = fexp(m, MOD - 2);
	//std::cout << "(" << pe << ", " << pg << ", " << inv << ")\n";
	for(int i = 0; i < n; i++) {
		if(a[i] && b[i]) {
			if(a[i] > b[i]) {
				ans += equal;
				equal = 0;
			} else if(a[i] < b[i]) {
				equal = 0;
			}
		} else if(!a[i] && b[i]) {
			ans += inv * (m - b[i]) % MOD * equal % MOD;
			equal = equal * inv % MOD;
		} else if(a[i] && !b[i]) {
			ans += inv * (a[i] - 1) % MOD * equal % MOD;
			equal = equal * inv % MOD;
		} else {
			ans += pg * equal % MOD;
			equal = equal * pe % MOD;
		}
		ans %= MOD;
		//std::cout << "on " << i << " got " << ans << ", " << equal << "\n";
	}
	std::cout << ans % MOD << '\n';
}