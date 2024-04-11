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
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x-1].first = i;
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x-1].second = i;
	}
	std::sort(a.begin(), a.end());
	std::vector<int> lis;
	for(auto p : a) {
		int x = -p.second;
		int id = std::lower_bound(lis.begin(), lis.end(), x) - lis.begin();
		if(id == (int) lis.size()) {
			lis.push_back(0);
		}
		lis[id] = x;
	}
	std::cout << lis.size() << std::endl;
}