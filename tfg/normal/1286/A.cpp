#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

int n;
int memo[ms][ms][2];
int a[ms];
int dp(int on, int zero, int one, int last) {
	if(zero<0 || one<0) return 1e9;
	if(on == n) return 1;
	int &ans = memo[on][zero][last];
	if(ans != 0) return ans;
	if(a[on] == 0) {
		return ans = dp(on+1, zero-1, one, 0) + (0+last)%2;
	} else if(a[on] == 1) {
		return ans = dp(on+1, zero, one-1, 1) + (1+last)%2;
	} else {
		return ans = std::min(dp(on+1, zero-1, one, 0) + (0+last)%2, dp(on+1, zero, one-1, 1) + (1+last)%2);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	int f[2] = {(n + 1) / 2, n / 2};
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i]--;
		if(a[i] >= 0) a[i] %= 2;
	}
	std::cout << std::min(dp(0, f[0], f[1], 0), dp(0, f[0], f[1], 1)) - 1 << '\n';
}