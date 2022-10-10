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
		int n, d;
		std::cin >> n >> d;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			int used = i == 0 ? x : std::min(x, d / i);
			d -= used * i;
			ans += used;
		}
		std::cout << ans << std::endl;
	}
}