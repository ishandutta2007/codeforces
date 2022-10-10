#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

long long fexp(long long x, long long e, long long mod = MOD) {
	long long ans = 1;
	x %= mod;
	for(; e > 0; e /= 2, x = x * x % mod) {
		if(e & 1) ans = ans * x % mod;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<long long> b(n+1, 0);
	for(int i = 0; i < n; i++) {
		b[i+1] = b[i] + a[i];
	}
	for(int i = 1; i <= n; i++) {
		long long ans = 0;
		for(int j = n-i-1, x = 1; j >= 0; j -= i, x++) {
			ans += x * (b[j+1] - b[std::max(j+1-i, 0)]);
		}
		std::cout << ans % MOD * fexp(n, MOD - 2) % MOD << (i == n ? '\n' : ' ');
	}
}