#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 505;

int memo[ms][ms], a[ms];

long long dp(int l, int r) {
	int &ans = memo[l][r];
	if(ans != -1) return ans;
	ans = 0;
	if(l + 1 >= r) return ans = 1;
	ans = (int) dp(l+1, r);
	for(int i = l+1; i < r; i++) {
		if(a[l] < a[i]) {
			ans = (int) ((ans + dp(l+1, i) * dp(i, r)) % MOD);
		}
	}
	return ans;
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	memset(memo, -1, sizeof memo);
	std::cout << dp(1, n) << '\n';
}