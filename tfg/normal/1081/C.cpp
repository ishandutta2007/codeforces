#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const long long MOD = 998244353;

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

long long fat[ms], ifat[ms];

long long comb(int n, int a) {
	if(a > n || a < 0) return 0;
	else return fat[n] * ifat[a] % MOD * ifat[n-a] % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % MOD;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	std::cin >> n >> m >> k;
	long long col = m * fexp(m - 1, k) % MOD;
	// k + 1 groups, sum is n - (k + 1)
	// n - (k + 1) + k choose k
	// n - 1 choose k
	long long dist = comb(n - 1, k);
	//std::cout << "col is " << col << ", dist is " << dist << "\n";
	std::cout << col * dist % MOD << '\n';
}