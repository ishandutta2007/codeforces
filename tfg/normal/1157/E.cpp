#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::multiset<int> b;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		b.insert(x);
	}
	for(auto v : a) {
		int want = (n - v) % n;
		auto it = b.lower_bound(want);
		if(it == b.end()) {
			it = b.begin();
		}
		std::cout << (v + *it) % n << ' ';
		b.erase(it);
	}
	std::cout << '\n';
}