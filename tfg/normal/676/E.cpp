#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	long long cur = 0;
	int turns = 0;
	const int UNKNOWN = 1278631;
	std::vector<long long> values;
	for(int i = 0; i <= n; i++) {
		std::string str;
		std::cin >> str;
		if(str == "?") {
			values.push_back(UNKNOWN);
			turns++;
		} else {
			values.push_back(atoi(str.c_str()));
		}
	}
	for(int i = n; i >= 0; i--) {
		if(std::abs(cur) > (long long) 1e9) break;
		if(values[i] == UNKNOWN) cur *= k;
		else cur = cur * k + values[i];
	}
	if(k == 0) {
		if(values[0] == UNKNOWN) {
			std::cout << ((n ^ turns) % 2 == 1 ? "NO\n" : "YES\n");
		} else {
			std::cout << (values[0] == 0 ? "YES\n" : "NO\n");
		}
	} else if(turns) {
		std::cout << (n % 2 ? "YES\n" : "NO\n");
	} else {
		std::cout << (cur == 0 ? "YES\n" : "NO\n");
	}
}