#include <iostream>
#include <map>

typedef long long ll;

const int MOD = 1e9 + 7;
const int ms = 100100;

ll fexp(ll x, ll e = MOD - 2) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

int fat[ms], ifat[ms];

ll comb(int n, int a) {
	if(a < 0 || a > n) return 0;
	return (ll) fat[n] * ifat[a] % MOD * ifat[n - a] % MOD;
}

int main() {
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = (ll) fat[i - 1] * i % MOD;
		ifat[i] = fexp(fat[i]);
	}
	int n;
	std::cin >> n;
	std::map<int, int> freq;
	for(int j = 0; j < n; j++) {
		int x;
		std::cin >> x;
		for(int i = 2; i * i <= x; i++) {
			while(x % i == 0) {
				x /= i;
				freq[i]++;
			}
		}
		if(x > 1) {
			freq[x]++;
		}
	}
	int ans = 1;
	for(auto v : freq) {
		ans = (ll) ans * comb(n + v.second - 1, n - 1) % MOD;
	}
	std::cout << ans << std::endl;
}