#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::sort(p.begin(), p.end(), [&](auto v1, auto v2) { return b[v1] > b[v2]; });
	std::sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) {
		b[p[i]] = a[i];
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}