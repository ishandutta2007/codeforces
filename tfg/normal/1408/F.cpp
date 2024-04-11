#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<std::pair<int, int>> ans;
	int n;
	std::cin >> n;
	int size = 1;
	while(size + size <= n) {
		size += size;
	}
	for(int len = 1; len < size; len += len) {
		for(int i = 0; i < size; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				ans.emplace_back(i + j, i + j + len);
			}
		}
	}
	std::cout << 2*ans.size() << '\n';
	for(auto p : ans) {
		std::cout << p.first + 1 << ' ' << p.second + 1 << '\n';
	}
	for(auto p : ans) {
		std::cout << n-p.first << ' ' << n-p.second << '\n';
	}
}