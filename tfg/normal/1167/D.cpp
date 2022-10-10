#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int i = 0; i < n; i++) {
		if(str[i] == '(') {
			str[i] = char('0' + i % 2);
		} else {
			str[i] = char('0' + (i+1) % 2);
		}
	}
	std::cout << str << '\n';
}