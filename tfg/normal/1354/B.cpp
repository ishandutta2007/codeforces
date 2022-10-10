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
		std::string str;
		std::cin >> str;
		int f[3] = {0, 0, 0};
		int ans = (int) str.size() + 1;
		for(int l = 0, r = 0; l < (int) str.size(); l++) {
			while(std::min(f[0], std::min(f[1], f[2])) <= 0 && r < (int) str.size()) {
				f[str[r++] - '1']++;
			}
			if(std::min(f[0], std::min(f[1], f[2])) <= 0) break;
			ans = std::min(ans, r - l);
			f[str[l] - '1']--;
		}
		if(ans == (int) str.size() + 1) ans = 0;
		std::cout << ans << '\n';
	}
}