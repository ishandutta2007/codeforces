#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int len = 1; len * 4 < n; len++) {
		for(int i = 0; i + len * 4 < n; i++) {
			bool good = true;
			for(int j = 0; j <= 4; j++) {
				good = good && str[i + len * j] == '*';
			}
			if(good) {
				std::cout << "yes\n";
				return 0;
			}
		}
	}
	std::cout << "no\n";
}