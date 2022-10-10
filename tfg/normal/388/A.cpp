#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<int> piles;
	for(auto v : a) {
		int ans = -1;
		for(int i = 0; i < (int) piles.size(); i++) {
			if(piles[i] > v) continue;
			if(ans == -1 || piles[i] >= piles[v]) {
				ans = i;
			}
		}
		if(ans == -1) {
			piles.push_back(1);
		} else {
			piles[ans]++;
		}
	}
	std::cout << piles.size() << '\n';
}