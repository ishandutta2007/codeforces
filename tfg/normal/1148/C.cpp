#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for(auto &v : p) {
		std::cin >> v;
		v--;
	}
	std::vector< std::pair<int, int> > ans;
	auto op = [&](int i, int j) {
		assert(2 * (j - i) >= n);
		std::swap(p[i], p[j]);
		ans.emplace_back(i + 1, j + 1);
	};
	auto sswap = [&](int i, int j) {
		if(i == j) return;
		if(i < n / 2) {
			op(i, n-1);
			op(j, n-1);
			op(i, n-1);
		} else {
			op(0, i);
			op(0, j);
			op(0, i);
		}
	};
	int c1 = 0;

	for(int i = n-1; i >= n / 2; i--) {
		while(p[c1] < n / 2) c1++;
		if(p[i] < n / 2) {
			if(2 * (i - c1) >= n) {
				//std::cout << "first case" << std::endl;
				op(c1++, i);
			} else {
				//std::cout << "second case" << std::endl;
				op(0, n-1);
				op(c1++, n-1);
				op(0, i);
			}
		}
	}
	while(p[c1] < n / 2) c1++;
	assert(c1 == n / 2);
	for(int i = 0; i < n; i++) {
		while(i != p[i]) sswap(i, p[i]);
		//assert(i == p[i]);
	}
	for(int i = 0; i < n; i++) {
		assert(p[i] == i);
	}
	//assert((int) ans.size() <= 5 * n);
	std::cout << ans.size() << '\n';
	for(auto p : ans) {
		std::cout << p.first << ' ' << p.second << '\n';
	}
}