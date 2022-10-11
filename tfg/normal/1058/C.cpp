#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool can(const std::string &str, int x) {
	int cur_sum = 0;
	for(auto c : str) {
		cur_sum += c - '0';
		if(cur_sum == x) {
			cur_sum = 0;
		} else if(cur_sum > x) {
			return false;
		}
	}
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	int sum = 0;
	for(auto c : str) {
		sum += c - '0';
	}
	if(sum == 0) {
		std::cout << "YES\n";
		return 0;
	}
	for(int i = 1; i < sum; i++) {
		if(sum % i == 0 && can(str, i)) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}