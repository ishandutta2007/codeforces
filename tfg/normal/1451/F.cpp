#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::map<int, int> wtf;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				std::cin >> x;
				wtf[i+j] ^= x;
			}
		}
		bool good = false;
		for(auto it : wtf) good = good || it.second;
		std::cout << (good ? "Ashish\n" : "Jeel\n");
	}
}