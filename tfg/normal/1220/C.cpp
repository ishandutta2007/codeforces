#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	char mn = 'z'+1;
	for(auto c : str) {
		std::cout << (mn >= c ? "Mike\n" : "Ann\n");
		mn = std::min(mn, c);
	}
}