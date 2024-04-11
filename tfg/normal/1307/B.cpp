#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, x;
		std::cin >> n >> x;
		int ans = -1;
		int mx = 0;
		while(n--) {
			int d;
			std::cin >> d;
			if(d == x) {
				ans = 1;
			}
			mx = std::max(d, mx);
		}
		if(ans == -1) {
			ans = std::max(2, (x + mx - 1) / mx);
		}
		std::cout << ans << '\n';
	}
}