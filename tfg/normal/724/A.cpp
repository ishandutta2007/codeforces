#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string haha[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
	std::map<std::string, int> wtf;
	for(int i = 0; i < 7; i++) {
		wtf[haha[i]] = i;
	}
	auto read = [&]() {
		std::string str;
		std::cin >> str;
		return wtf[str];
	};
	int a = read();
	int b = read();
	if((a + 31) % 7 == b || (a + 30) % 7 == b || (a + 28) % 7 == b) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}