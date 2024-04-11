#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

long long fexp(long long x, int e = MOD - 2) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

const int ms = 66;

long long inv[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		inv[i] = fexp(i, MOD - 2);
	}
	long long ans = 1;
	long long n;
	int k;
	std::cin >> n >> k;
	std::map<int, std::vector<long long>> memo;
	auto getDP = [&](int size) {
		if(memo.count(size)) {
			return memo[size];
		}
		std::vector<long long> dp(size + 1, 0);
		dp[size] = 1;
		for(int i = 0; i < k; i++) {
			std::vector<long long> nxt(size + 2, 0);
			for(int j = 0; j <= size; j++) {
				nxt[0] = (nxt[0] + (long long) inv[j+1] * dp[j]) % MOD;
				nxt[j+1] = (nxt[j+1] - (long long) inv[j+1] * dp[j] % MOD + MOD) % MOD;
			}
			nxt.pop_back();
			for(int j = 1; j <= size; j++) {
				nxt[j] = (nxt[j] + nxt[j-1]) % MOD;
			}
			dp = nxt;
		}
		for(int i = 0; i <= size; i++) {
			dp[i] = (dp[i] % MOD + MOD) % MOD;
		}
		return memo[size] = dp;
	};
	for(int i = 2; (long long) i * i <= n; i++) {
		int e = 0;
		while(n % i == 0) {
			e++;
			n /= i;
		}
		if(e > 0) {
			auto v = getDP(e);
			long long cur = 0;
			for(int j = 0; j <= e; j++) {
				cur = ((long long) cur * i + v[e-j]) % MOD;
			}
			ans = (long long) ans * cur % MOD;
		}
	}
	if(n > 1) {
		int e = 1;
		long long i = n % MOD;
		if(e > 0) {
			auto v = getDP(e);
			long long cur = 0;
			for(int j = 0; j <= e; j++) {
				cur = ((long long) cur * i + v[e-j]) % MOD;
			}
			ans = (long long) ans * cur % MOD;
		}
	}
	std::cout << (ans % MOD + MOD) % MOD << '\n';
}