#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::string str;
	std::cin >> n >> k >> str;
	std::vector<int> sizes(k, 0);
	for(auto v : str) {
		sizes[v - 'A']++;
	}
	int mn = n;
	for(auto v : sizes) {
		mn = std::min(mn, v);
	}
	std::cout << mn * k << std::endl;
}