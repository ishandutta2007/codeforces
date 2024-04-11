#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const int mv = 200;
const int MOD = 998244353;

int memo[ms][mv][3];
int n;
int a[ms];

int dp(int on, int v, int cmp) {
	if(v < 0 || v >= mv) return 0;
	int &ans = memo[on][v][cmp];
	if(ans != -1) return ans;
	ans = 0;
	if(cmp == 2) {
		ans = (ans + dp(on, v - 1, 2)) % MOD;
	}
	if(cmp == 0) {
		ans = (ans + dp(on, v + 1, 0)) % MOD;
	}
	if(cmp == 1) {
		ans = (ans + dp(on, v + 1, 0)) % MOD;
		ans = (ans + dp(on, v - 1, 2)) % MOD;
	}
	if(a[on] != -1 && a[on] != v) return ans;
	// testing if can go down
	if(cmp == 0) {
		// means that this is a new peak
		if(on + 1 == n) {
			return ans;
		}
		ans = (ans + dp(on + 1, v, 1)) % MOD;
		ans = (ans - dp(on + 1, v - 1, 2)) % MOD;
	} else {
		// can get anything
		if(on + 1 == n) {
			ans = (ans + 1) % MOD;
			return ans;
		}
		ans = (ans + dp(on + 1, v, 1)) % MOD;
	}
	ans %= MOD;
	ans += MOD;
	ans %= MOD;
	//if(ans)
	//std::cout << "on (" << on << ", " << v << ", " << cmp << ") == " << ans << "\n";
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] != -1) a[i]--;
	}
	memset(memo, -1, sizeof memo);
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < mv; j++) {
			for(int k = 0; k < 3; k++) {
				dp(i, j, k);
			}
		}
	}
	std::cout << dp(0, 0, 0) << '\n';
}