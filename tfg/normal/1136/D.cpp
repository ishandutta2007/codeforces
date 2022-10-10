#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::set<std::pair<int, int>> st;
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		st.insert(std::pair<int, int>(u, v));
	}
	int id = p.back();
	for(int i = n-2; i >= 0; i--) {
		int j = i+1;
		while(j < n && st.count(std::pair<int, int>(p[j-1], p[j]))) {
			std::swap(p[j-1], p[j]);
			j++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(p[i] == id) {
			std::cout << n - i - 1 << '\n';
		}
	}
}