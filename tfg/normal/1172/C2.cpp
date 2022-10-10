#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 3030;
const int MOD = 998244353;

long long fexp(long long x, long long e = MOD - 2) {
	x = (x % MOD + MOD) % MOD;
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

int m;
int sum[3] = {0, 0, 0};
int memo[ms][ms];
int hehe[3 * ms];

template<const int T>
int dp(int down, int up) {
	int &ans = memo[down][up];
	if(ans != -1) return ans;
	ans = 0;
	int s[3] = {sum[0] - down, sum[1] + up, sum[2] + up - down};
	if(s[0] <= 0 && T == 0) return ans;
	if(down + up == m) return ans;
	if(T == 0) {
		// disliked
		long long frac = hehe[ms+up-down];
		ans += (long long) dp<T>(down+1, up) * (s[0]-1) % MOD * frac % MOD;
		ans += (long long) dp<T>(down, up+1) * s[1] % MOD * frac % MOD;
		ans %= MOD;
		ans += MOD - frac;
		ans %= MOD;
	} else {
		// liked
		long long frac = hehe[ms+up-down];
		ans += (long long) dp<T>(down+1, up) * s[0] % MOD * frac % MOD;
		ans += (long long) dp<T>(down, up+1) * (s[1]+1) % MOD * frac % MOD;
		ans %= MOD;
		ans += frac;
		ans %= MOD;
	}
	//std::cout << "at " << down << ", " << up << " with T " << T << " got " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> m;
	std::vector<int> a(n), w(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> w[i];
		sum[a[i]] += w[i];
		sum[2] += w[i];
	}
	for(int i = 0; i < 3*ms; i++) {
		hehe[i] = fexp(sum[2]+i-ms);
	}
	std::vector<int> ans(n);
	if(sum[0] > 0) {
		// solving for disliked
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < n; i++) {
			if(a[i] == 0) {
				ans[i] = (long long) w[i] * (dp<0>(0, 0)+1) % MOD;
			}
		}
	}
	if(sum[1] > 0) {
		// solving for liked
		memset(memo, -1, sizeof memo);
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) {
				ans[i] = (long long) w[i] * (dp<1>(0, 0)+1) % MOD;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << '\n';
	}
}