#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solve(long long x) {
	if(x == 0) {
		return 0;
	} else {
		return int(x % 10) + solve(x / 10);
	}
}

int solve1(long long n) {
	int ans = 0;
	for(long long i = 0; i <= n; i = i * 10 + 9) {
		ans = std::max(ans, solve(i) + solve(n - i));
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	std::cin >> n;
	/*if(0) {
		for(int i = 0; i <= n; i++) {
			int ans = 0;
			for(int j = 0; j <= i - j; j++) {
				ans = std::max(ans, solve(j) + solve(i - j));
			}
			if(solve1(i) != ans) {
				std::cout << "bug on " << i << ", (" << solve1(i) << ", " << ans << ")\n";
			}
		}
	}*/
	std::cout << solve1(n) << std::endl;
}