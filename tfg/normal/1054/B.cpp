#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int mex = 0;
	for(int i = 1; i <= n; i++) {
		int v;
		std::cin >> v;
		if(v == mex) {
			mex++;
		} else if(v > mex) {
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << "-1\n";
}