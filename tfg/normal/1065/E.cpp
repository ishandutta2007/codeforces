#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;
const long long MOD = 998244353;

long long fexp(long long x, long long e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

long long fat[ms], ifat[ms];

long long comb(int n, int a) {
	return fat[n] * ifat[a] % MOD * ifat[n - a] % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % MOD;
		ifat[i] = fexp(fat[i]);
	}
	int n, m, a;
	std::cin >> n >> m >> a;
	long long ans = 1;
	int last = 0;
	for(int i = 0; i < m; i++) {
		int pos;
		std::cin >> pos;
		long long equal = fexp(a, pos - last);
		long long diff = (fexp(a, 2 * (pos - last)) - equal + MOD) % MOD;
		long long cur = (equal + diff * fexp(2)) % MOD;
		ans = ans * cur % MOD;
		//std::cout << "for " << i << " got " << equal << ", " << cur << "\n";
		last = pos;
	}
	ans = ans * fexp(a, n - 2 * last) % MOD;
	std::cout << ans << std::endl;
}