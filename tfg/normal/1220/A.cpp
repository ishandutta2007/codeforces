#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::vector<int> freq(26, 0);
	std::cin >> n >> str;
	for(auto i : str) {
		freq[i - 'a']++;
	}
	while(freq['n' - 'a']--) {
		std::cout << "1 ";
	}
	while(freq['z' - 'a']--) {
		std::cout << "0 ";
	}
	std::cout << '\n';
}