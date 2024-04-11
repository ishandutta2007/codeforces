#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int MOD = 998244353;
	int n, m;
	std::cin >> n >> m;
	int ans = 1;
	for(int i = 0; i < n + m; i++) {
		ans = (ans + ans) % MOD;
	}
	std::cout << ans << '\n';
}