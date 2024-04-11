#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int ans = n-1;
	for(int i = 1; i < n; i++) {
		if(str[i] < str[i-1]) {
			ans = i-1;
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(i != ans) {
			std::cout << str[i];
		}
	}
	std::cout << '\n';
}