#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = 1e9 + 7;
const int ms = 100100;

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

std::vector<int> divs[ms];
long long dp[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j += i) {
			divs[j].push_back(i);
		}
	}
	/*long long cost = 0;
	for(int i = 1; i <= n; i++) {
		cost += (long long) divs[i].size() * divs[i].size();
	}
	std::cout << cost << '\n';*/
	dp[1] = 0;
	for(int i = 2; i <= n; i++) {
		std::vector<long long> trans(divs[i].size(), 0);
		for(int j = (int) divs[i].size() - 1; j >= 0; j--) {
			trans[j] = n / divs[i][j];
			for(int k = j + 1; k < (int) divs[i].size(); k++) {
				if(divs[i][k] % divs[i][j] == 0) trans[j] -= trans[k];
			}
		}
		// expected length until next
		// probability is (n - back) / n
		// length is n / (n - back)
		long long q = fexp(n - trans.back(), MOD - 2);
		long long base = n * q % MOD;
		for(int j = 0; j < (int) divs[i].size() - 1; j++) {
			// probability to get here is freq / (n - back)
			dp[i] = (dp[i] + trans[j] * q % MOD * dp[divs[i][j]]) % MOD;
		}
		dp[i] = (dp[i] + base) % MOD;
		//std::cout << "base for " << i << " is " << base << '\n';
		//std::cout << "dp[" << i << "] = " << dp[i] << '\n';
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	ans = ans * fexp(n, MOD - 2) % MOD;
	ans = (ans + 1) % MOD;
	std::cout << ans << '\n';
}