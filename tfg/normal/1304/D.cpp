#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve1(int l, int r, std::string str) {
	l = 0;
	for(auto c : str) {
		if(c == '<') l++;
	}
	for(int i = 0, j = 0; i < (int) str.size(); i = j) {
		while(j < (int) str.size() && str[i] == str[j]) j++;
		if(str[i] == '>') {
			for(int x = 0; x < j - i; x++) {
				std::cout << r-- << ' ';
			}
		} else {
			for(int x = 0; x < j - i; x++) {
				std::cout << l - (j-i-1) + x << ' ';
			}
			l -= j - i;
		}
	}
	std::cout << r << '\n';
}

void solve2(int l, int r, std::string str) {
	for(int i = 0, j = 0; i < (int) str.size(); i = j) {
		while(j < (int) str.size() && str[i] == str[j]) j++;
		if(str[i] == '>') {
			for(int x = 0; x < j - i; x++) {
				std::cout << l + (j-i) - x << ' ';
			}
			std::cout << l << ' ';
			l += (j - i) + 1;
		} else {
			for(int x = i == 0 ? 0 : 1; x < j - i; x++) {
				std::cout << l++ << ' ';
			}
		}
	}
	if(str.back() == '<') {
		std::cout << (int) str.size() + 1 << '\n';
	} else {
		std::cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int l, r;
		l = 1;
		std::string str;
		std::cin >> r >> str;
		solve1(l, r, str);
		solve2(l, r, str);
	}
}