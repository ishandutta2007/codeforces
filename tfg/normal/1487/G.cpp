#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 410;
const int MOD = 998244353;

// mask for last ones has 4 values
// 0 for blocking nothing
// 1 for blocking f1
// 2 for blocking f2
// 3 for blocking 24
int memo[ms][ms/2][ms/2][9];

int dp(int n, int f1, int f2, int m1, int m2) {
	f1 = std::min(f1, n / 2 + 2);
	f2 = std::min(f2, n / 2 + 2);
	f1 = std::max(f1, -1);
	f2 = std::max(f2, -1);
	//assert(f1+1 < ms/2 && f2+1 < ms/2);
	if(n == 0) return f1 + f2 == -2 ? 1 : 0;
	//if(m1 == 0 || m2 == 0) return (int) (((m1 == 1 ? 0 : dp(n-1, f1-1, f2, m2, 1)) + (m1 == 2 ? 0 : dp(n-1, f1, f2-1, m2, 2)) + (m1 == 3 ? 23LL : 24LL) * dp(n-1, f1, f2, m2, 3)) % MOD);
	int &ans = memo[n][f1+1][f2+1][(m1-1)*3+m2-1];
	if(ans != -1) return ans;
	return ans = (int) (((m1 == 1 ? 0 : dp(n-1, f1-1, f2, m2, 1)) + (m1 == 2 ? 0 : dp(n-1, f1, f2-1, m2, 2)) + (m1 == 3 ? 23LL : 24LL) * dp(n-1, f1, f2, m2, 3)) % MOD);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	memset(memo, -1, sizeof memo);
	std::vector<int> f(26);
	for(int i = 0; i < 26; i++) {
		std::cin >> f[i];
	}
	long long ans = dp(n, -1, -1, 0, 0);
	//std::cout << ans << '\n';
	for(int i = 0; i < 26; i++) {
		ans -= dp(n, f[i], -1, 0, 0);
		//std::cout << "at " << f[i] << " got " << dp(n, f[i], -1, 0, 0) << '\n';
		for(int j = i+1; j < 26; j++) {
			ans += dp(n, f[i], f[j], 0, 0);
		}
	}
	std::cout << (ans % MOD + MOD) % MOD << '\n';
}