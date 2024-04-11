#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, r;
	std::cin >> n >> r;
	int ans = 0;
	std::vector<int> h(n);
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	std::vector<int> got(n, 0);
	for(int i = 0; i < n; i++) {
		if(got[i]) continue;
		int id = -1;
		for(int j = std::min(n - 1, i + r - 1); j >= 0; j--) {
			if(h[j]) {
				id = j;
				break;
			}
		}
		if(id == -1) {
			std::cout << "-1\n";
			return 0;
		}
		for(int k = std::max(0, id - r + 1); k < n && k < id + r; k++) {
			got[k] = 1;
		}
		if(!got[i]) {
			std::cout << "-1\n";
			return 0;
		}
		ans++;
	}
	std::cout << ans << std::endl;
}