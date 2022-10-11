#include <iostream>

typedef long long ll;

const ll MOD = 1e9 + 7;
const int ms = 5002;

int comb[ms][ms];
int cof[ms][ms]; // cof[a][b] has for a diferentiations, x ^ b * (1 + x) ^ (n - b)

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
	comb[0][0] = 1;
	for(int i = 0; i + 1 < ms; i++) {
		for(int j = 0; j + 1 < ms; j++) {
			comb[i][j] %= MOD;
			comb[i + 1][j] += comb[i][j];
			comb[i + 1][j + 1] += comb[i][j];
		}
	}
	ll n, k;
	std::cin >> n >> k;
	cof[0][0] = 1;
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= i; j++) {
			cof[i][j] = ((ll)cof[i - 1][j] * j + (ll)cof[i - 1][j - 1] * (n - j + 1)) % MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= std::min(k, n); i++) {
		ans = (ans + cof[k][i] * fexp(2, n - i)) % MOD;
	}
	std::cout << ans << '\n';
}