#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

long long memo[ms][ms], memo2[ms][ms][ms];
long long a[ms];
std::string str;

long long dp(int l, int r);

long long dp2(int l, int r, int x) {
	if(r - l <= 0) return 0;
	long long &ans = memo2[l][r][x];
	if(ans != -1) return ans;
	ans = dp(l+1, r) + a[x];
	for(int i = l+1; i < r; i++) {
		if(str[i] == str[l]) {
			ans = std::max(ans, dp(l+1, i) + dp2(i, r, x+1));
		}
	}
	return ans;
}

long long dp(int l, int r) {
	if(r - l <= 0) return 0;
	else if(r - l == 1) return a[1];
	long long &ans = memo[l][r];
	if(ans != -1) return ans;
	ans = 0;
	for(int m = l; m < r; m++) {
		ans = std::max(ans, dp2(m, r, 1) + dp(l, m));
	}
	return ans;
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> str;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i+1];
	}
	memset(memo, -1, sizeof memo);
	memset(memo2, -1, sizeof memo2);
	std::cout << dp(0, n) << '\n';
}