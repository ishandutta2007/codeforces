#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::map<int, int> f;
		while(n--) {
			int x;
			std::cin >> x;
			f[x]++;
		}
		for(int i = 0; f[i]; i++) {
			std::cout << i << ' ';
			f[i]--;
		}
		for(auto it : f) {
			while(it.second--) {
				std::cout << it.first << ' ';
			}
		}
		std::cout << '\n';
	}
}