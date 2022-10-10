#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	std::vector<long long> single(26, 0);
	std::vector<std::vector<long long>> two(26, std::vector<long long>(26, 0));
	for(auto c : str) {
		for(int i = 0; i < 26; i++) {
			two[i][c-'a'] += single[i];
		}
		single[c-'a']++;
	}
	long long ans = 0;
	for(auto x : single) {
		ans = std::max(ans, x);
	}
	for(auto v : two) {
		for(auto x : v) {
			ans = std::max(ans, x);
		}
	}
	std::cout << ans << std::endl;
}