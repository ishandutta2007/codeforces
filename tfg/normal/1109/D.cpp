#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 2002000;

long long fexp(long long x, int e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

long long fat[ms], ifat[ms];

long long comb(int n, int a) {
	if(a < 0 || a > n || n < 0) return 0;
	return fat[n] * ifat[a] % MOD * ifat[n-a] % MOD;
}

long long solve(int n, int k) {
	if(n == 1) return 1;
	return k * fexp(k + n - 1, n - 2) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, trasha, trashb;
	std::cin >> n >> m >> trasha >> trashb;
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % MOD;
		ifat[i] = fexp(fat[i]);
	}
	long long ans = 0;
	for(int i = 2; i <= n; i++) {
		// count number of ways to fill edges outside
		long long edges = fexp(m, n - i);
		// count number of ways to choose edges
		//edges = edges * fexp(n - i + 1, n - i + 1 - 2) % MOD;
		// count number of ways to fill path
		edges = edges * comb(m - (i - 1) + (i - 1) - 1, (i - 1) - 1) % MOD;
		// count number of ways to permutate
		long long verts = comb(n - 2, i - 2) * fat[i - 2] % MOD;
		// please work
		verts = verts * solve(n - i + 1, i) % MOD;
		// thx mr prufer sequence
		//std::cout << "for " << i << " got (" << edges << ", " << verts << ")\n";
		ans = (ans + edges * verts) % MOD;
	}
	ans = (ans % MOD + MOD) % MOD;
	std::cout << ans << '\n';
}