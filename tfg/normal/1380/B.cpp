#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int f(char ch) {
	if(ch == 'R') {
		return 0;
	} else if(ch == 'S') {
		return 1;
	} else {
		return 2;
	}
}

char g(int id) {
	if(id == 0) {
		return 'R';
	} else if(id == 1) {
		return 'S';
	} else {
		return 'P';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		int freq[3] = {0, 0, 0};
		for(auto ch : str) {
			freq[f(ch)]++;
		}
		int ans = 0;
		for(int i = 1; i < 3; i++) {
			if(freq[i] > freq[ans]) ans = i;
		}
		std::cout << std::string(str.size(), g((ans+2)%3)) << '\n';
	}
}