#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 1e9 + 7;

long long sum(long long x) { return x * (x + 1) % MOD; }

long long solve(long long x) {
	if(x == 0) return 0;
	long long pt[2] = {0, MOD - 1};
	long long size = 1;
	long long ans = 0;
	int st = 1;
	while(x > 0) {
		size = std::min(size, x);
		ans = (ans + pt[st] % MOD * (size % MOD) % MOD + sum(size % MOD)) % MOD;
		pt[st] = (pt[st] + 2 * size) % MOD;
		st = 1 - st;
		x -= size;
		size += size;
	}
	return (ans % MOD + MOD) % MOD;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long l, r;
	std::cin >> l >> r;
	//std::cout << "f(" << r << ") = " << solve(r) << '\n';
	//std::cout << "f(" << l-1 << ") = " << solve(l-1) << '\n';
	std::cout << (solve(r) - solve(l-1) + MOD) % MOD << '\n';
}