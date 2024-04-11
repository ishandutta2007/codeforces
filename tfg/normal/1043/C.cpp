#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	std::string best = "";
	std::vector<int> ans;
	for(auto c : str) {
		if(c + best < best + c) {
			ans.back() ^= 1;
			ans.push_back(1);
			best = c + best;
		} else {
			ans.push_back(0);
			best = best + c;
		}
	}
	for(int i = 0; i < (int) str.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) str.size() ? '\n' : ' ');
	}
}