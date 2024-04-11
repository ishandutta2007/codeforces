#include <iostream>

typedef long long ll;

const int ms = 2020;
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

ll a[ms], ans[ms];
ll trans[ms];

int main() {
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if(k == 0) {
		trans[0] = 1;
	} else {
		trans[0] = 1;
		for(int i = 1; i < n; i++) {
			trans[i] = trans[i - 1] * (i + k - 1) % MOD * fexp(i, MOD - 2) % MOD;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			ans[j] = (ans[j] + a[i] * trans[j - i]) % MOD;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}