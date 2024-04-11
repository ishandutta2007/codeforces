#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int INF = 1e9;
	std::vector<int> ans(181, INF);
	for(int i = 3; i <= 360; i++) {
		for(int j = 3; j <= i; j++) {
			// total angle = 180 * (j - 2) = 2 * wanted + (j - 2) * 180 * (i - 2) / i
			// 2 * wanted = 180 * (j - 2) - (j - 2) * 180 * (i - 2) / i
			// wanted = 90 * (j - 2) * (1 - (i - 2) / i)
			// wanted = (j - 2) * (90 - 90 * (i - 2) / i)
			if((j - 2) * 90 * (i - 2) % i == 0) {
				int angle = ((j - 2) * 90 - (j - 2) * 90 * (i - 2) / i);
				ans[angle] = std::min(ans[angle], i);
			}
		}
	}
	for(int i = 0; i <= 180; i++) {
		if(ans[i] >= INF) {
			ans[i] = -1;
		}
		//std::cout << i << ": " << ans[i] << "\n";
	}
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::cout << ans[n] << '\n';
	}
}