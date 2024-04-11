#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;
	std::string str = "abc";
	do {
		bool valid;
		// first check
		// groups of same letter
		valid = true;
		for(int i = 0; i < 2; i++) {
			valid = valid && (str[i] != s[0] || str[i+1] != s[1]);
			valid = valid && (str[i] != t[0] || str[i+1] != t[1]);
		}
		if(n > 1) {
			valid = valid && s[0] != s[1];
			valid = valid && t[0] != t[1];
		}
		if(valid) {
			std::cout << "YES\n";
			for(int i = 0; i < 3*n; i++) {
				std::cout << str[i/n];
			}
			std::cout << '\n';
			return 0;
		}
		// second check
		// little chuncks of 3
		valid = true;
		for(int i = 0; i < 2; i++) {
			valid = valid && (str[i] != s[0] || str[i+1] != s[1]);
			valid = valid && (str[i] != t[0] || str[i+1] != t[1]);
		}
		if(n > 1) {
			valid = valid && (str[2] != s[0] || str[0] != s[1]);
			valid = valid && (str[2] != t[0] || str[0] != t[1]);
		}
		if(valid) {
			std::cout << "YES\n";
			for(int i = 0; i < 3*n; i++) {
				std::cout << str[i%3];
			}
			std::cout << '\n';
			return 0;
		}
	} while(std::next_permutation(str.begin(), str.end()));
	assert(0);
	std::cout << "NO\n";
}