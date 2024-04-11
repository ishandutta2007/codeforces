#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int ans[3] = {-1, -1, -1};
		int n;
		std::cin >> n;
		for(int i = 0; i < 3; i++) for(int j = 0; j < 3 && i * 5 + j * 7 <= n; j++) {
			int k = (n - i * 5 - j * 7) / 3;
			if(i * 5 + j * 7 + k * 3 == n) {
				ans[0] = k, ans[1] = i, ans[2] = j;
			}
		}
		if(ans[0] == -1) {
			std::cout << "-1\n";
		} else {
			std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
		}
	}
}