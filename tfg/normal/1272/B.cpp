#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int dir(char c) {
	if(c == 'U') {
		return 0;
	} else if(c == 'D') {
		return 1;
	} else if(c == 'R') {
		return 2;
	} else {
		return 3;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		std::vector<int> freq(4, 0);
		for(auto c : str) {
			freq[dir(c)]++;
		}
		for(int i = 0; i < 4; i++) {
			freq[i] = std::min(freq[i], freq[i^1]);
		}
		if(freq[0] == 0) {
			freq[2] = std::min(freq[2], 1);
		}
		if(freq[2] == 0) {
			freq[0] = std::min(freq[0], 1);
		}
		for(int i = 0; i < 4; i++) {
			freq[i] = std::min(freq[i], freq[i^1]);
		}
		std::cout << freq[0] + freq[1] + freq[2] + freq[3] << '\n';
		std::cout << (std::string(freq[0], 'U') + std::string(freq[2], 'R') + std::string(freq[1], 'D') + std::string(freq[3], 'L')) << '\n';
	}
}