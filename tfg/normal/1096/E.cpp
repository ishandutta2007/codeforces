#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

const long long MOD = 998244353;

long long fexp(long long x, long long e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

long long inv[ms];
long long fat[ms], ifat[ms];

long long comb(int n, int a) {
	if(a < 0 || a > n) return 0;
	else return fat[n] * ifat[a] % MOD * ifat[n-a] % MOD;
}

long long sum(int S, int K, int m) {
	if(S == 0 && K == 0) return 1;
	// sum(S, K, m) ways to sum S using K numbers < m
	//std::cout << "entering (" << S << ", " << K << ")" << std::endl;
	long long ans = 0;
	for(int i = 0; i <= K && i * m <= S; i++) {
		// ways to sum S - i * m with K numbers
		long long cur = comb(S - i * m + K - 1, K - 1) * comb(K, i) % MOD;
		if(i % 2 == 1) {
			cur = (MOD - cur) % MOD;
		}
		ans = (ans + cur) % MOD;
	}
	//std::cout << "for (" << S << ", " << K << ", " << m << ") got " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int p, s, r;
	std::cin >> p >> s >> r;
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		inv[i] = fexp(i);
		fat[i] = fat[i-1] * i % MOD;
		ifat[i] = ifat[i-1] * inv[i] % MOD;
	}
	long long q = 0;
	long long ans = 0;
	for(int v = r; v <= s; v++) {
		// my value is v
		for(int o = 0; o + 1 <= p && v * (o + 1) <= s; o++) {
			// o people have the same as me
			int x = p - (o + 1);
			// x people have < v
			if(x > 0 && v == 0) continue;
			// has to answer
			// sum(S, K, m) ways to sum S using K numbers < m
			// ways to sum S using K numbers >= m
			ans = (ans + sum(s - v * (o + 1), x, v) * comb(p-1, o) % MOD * inv[o + 1]) % MOD;
		}
		q = (q + sum(s - v, p-1, s + 1)) % MOD;
	}
	//std::cout << ans << " / " << q << "\n";
	std::cout << ans * fexp(q) % MOD << '\n';
}