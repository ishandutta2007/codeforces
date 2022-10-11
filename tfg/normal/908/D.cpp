#include <iostream>
#include <cstring>

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

int k;
int a, b, pa, pb, r;

int memo[1010][1010];

int dp(int as, int bs) {
	if(bs >= k) {
		return bs;
	}
	if(as >= k) {
		return ((ll)bs + as + r) % MOD;
	}
	int &ans = memo[as][bs];
	if(ans != -1) {
		return ans;
	}
	ans = ((ll) pb * dp(as, bs + as) + (ll) pa * dp(as + 1, bs)) % MOD;
	return ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	std::cin >> k >> a >> b;
	pa = a * fexp(a + b, MOD - 2) % MOD;
	pb = b * fexp(a + b, MOD - 2) % MOD;
	r = fexp(pb, MOD - 2);
	r = (r + MOD - 1) % MOD;
	std::cout << dp(1, 0) << '\n';
}