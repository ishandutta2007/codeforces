#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n, 0);
	for(int i = 0; i < k; i++) {
		int x;
		std::cin >> x;
		a[x-1] = 1;
	}
	int q;
	std::cin >> q;
	std::vector<std::pair<int, int>> range;
	int mx1 = 0;
	int mx2 = 0;
	while(q--) {
		{
			std::string trash;
			std::cin >> trash;
		}
		int size;
		std::cin >> size;
		int good = 0;
		int bad = 0;
		int notsure = 0;
		for(int i = 0; i < size; i++) {
			int x;
			std::cin >> x;
			if(x == 0) {
				notsure++;
			} else if(a[x-1]) {
				good++;
			} else {
				bad++;
			}
		}
		range.emplace_back(good + std::max(0, bad+notsure - (n-k)), std::min(good+notsure, k));
		mx1 = std::max(mx1, range.back().first);
		mx2 = std::max(mx2, range.back().second);
	}
	n = (int) range.size();
	for(int i = 0; i < n; i++) {
		bool valid = true;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			valid = valid && range[i].first >= range[j].second;
		}
		if(valid) {
			std::cout << "0\n";
			continue;
		}
		valid = true;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			valid = valid && range[i].second >= range[j].first;
		}
		if(valid) {
			std::cout << "2\n";
		} else {
			std::cout << "1\n";
		}
	}
}