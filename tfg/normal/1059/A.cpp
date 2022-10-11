#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int ans = 0;
	int n, l, a;
	std::cin >> n >> l >> a;
	int on = 0;
	while(n--) {
		int t, len;
		std::cin >> t >> len;
		ans += (t - on) / a;
		on = t + len;
	}
	ans += (l - on) / a;
	std::cout << ans << std::endl;
}