#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		int mx = 0, sum = 0;
		while(n--) {
			int x;
			std::cin >> x;
			mx = std::max(mx, x);
			sum += x;
		}
		if(mx * 2 > sum || sum % 2 == 1) {
			std::cout << "T\n";
		} else {
			std::cout << "HL\n";
		}
	}
}