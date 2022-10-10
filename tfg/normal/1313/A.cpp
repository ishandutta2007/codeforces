#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		std::vector<std::vector<int>> a;
		int f[3];
		std::cin >> f[0] >> f[1] >> f[2];
		for(int i = 1; i < 8; i++) {
			std::vector<int> b;
			for(int j = 0; j < 3; j++) {
				if(i & (1 << j)) b.push_back(j);
			}
			a.push_back(b);
		}
		int ans = 0;
		for(int i = 1; i < (1 << 7); i++) {
			int o[3] = {0, 0, 0};
			int got = 0;
			for(int j = 0; j < 7; j++) {
				if(i & (1 << j)) {
					got++;
					for(auto x : a[j]) {
						o[x]++;
						if(o[x] > f[x]) {
							got = -10;
						}
					}
				}
			}
			ans = std::max(ans, got);
		}
		std::cout << ans << '\n';
	}
}