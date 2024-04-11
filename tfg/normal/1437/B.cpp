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
		int n;
		std::string str;
		std::cin >> n >> str;
		int ans[2] = {0, 0};
		for(int i = 0; i+1 < n; i++) {
			if(str.substr(i, 2) == "00") {
				ans[0]++;
			} else if(str.substr(i, 2) == "11") {
				ans[1]++;
			}
		}
		std::cout << std::max(ans[0], ans[1]) << '\n';
	}
}