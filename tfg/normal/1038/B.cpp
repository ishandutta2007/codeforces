#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int sum = n * (n + 1) / 2;
	for(int i = 1; i < sum; i++) {
		int j = sum - i;
		if(gcd(i, j) != 1) {
			std::cout << "Yes\n";
			std::vector<int> v[2];
			int want = i;
			for(int va = n; va > 0; va--) {
				if(va <= want) {
					want -= va;
					v[1].push_back(va);
				} else {
					v[0].push_back(va);
				}
			}
			for(int k = 0; k < 2; k++) {
				std::cout << v[k].size() << ' ';
				for(int l = 0; l < (int) v[k].size(); l++) {
					std::cout << v[k][l] << (l + 1 == (int) v[k].size() ? '\n' : ' ');
				}
			}
			return 0;
		}
	}
	std::cout << "No\n";
}