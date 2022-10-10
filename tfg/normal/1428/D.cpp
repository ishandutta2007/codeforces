#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// 2 has to be paired with some 1 to the right
	std::vector<int> two;
	// 3 has to be paired with some 1, 2 or 3
	std::vector<int> three;
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> ans;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		if(x == 0) {

		} else if(x == 1) {
			// priority of pairing is 2
			if(!two.empty()) {
				ans.emplace_back(two.back(), i);
				two.pop_back();
			} else if(!three.empty()) {
				ans.emplace_back(three.back(), i);
				ans.emplace_back(i, i);
				three.pop_back();
			} else {
				ans.emplace_back(i, i);
			}
		} else if(x == 2) {
			if(!three.empty()) {
				ans.emplace_back(three.back(), i);
				three.pop_back();
			}
			ans.emplace_back(i, i);
			two.push_back(i);
		} else {
			if(!three.empty()) {
				ans.emplace_back(three.back(), i);
				three.pop_back();
			}
			ans.emplace_back(i, i);
			three.push_back(i);
		}
	}
	if(!two.empty() || !three.empty()) {
		std::cout << "-1\n";
	} else {
		std::cout << ans.size() << '\n';
		for(auto p : ans) {
			std::cout << p.first+1 << ' ' << p.second+1 << '\n';
		}
	}
}