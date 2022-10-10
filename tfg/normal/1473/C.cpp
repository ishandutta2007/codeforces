#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		int id = 2 * k - n - 1;
		//std::cout << "id is " << id << std::endl;
		for(int i = 1; i <= k; i++) {
			std::cout << (i <= id ? i : k - (i - (id+1))) << (i == k ? '\n' : ' ');
		}
	}
}