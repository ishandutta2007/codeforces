#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	std::string str;
	std::cin >> str;
	int f[2] = {0, 0};
	for(auto ch : str) f[ch - '0']++;
	if(std::min(f[0], f[1]) % 2 == 1) {
		std::cout << "DA\n";
	} else {
		std::cout << "NET\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}