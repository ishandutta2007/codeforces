#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int qry(int a, int b, int c) {
	assert(a != b && b != c && a != c);
	std::cout << "? " << a+1 << ' ' << b+1 << ' ' << c+1 << std::endl;
	std::cin >> a;
	return a-1;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int h;
	std::cin >> h;
	int n = (1 << h) - 1;
	std::vector<int> a(n, 0);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	std::uniform_int_distribution<int> dist(0, n-1);
	for(int i = 1; i <= 420; i++) {
		int v1, v2, v3;
		do {
			v1 = dist(rng), v2 = dist(rng), v3 = dist(rng);
		} while(v1 == v2 || v1 == v3 || v2 == v3);
		a[qry(v1, v2, v3)]++;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] > a[v2]; });
	for(int i = 0; i < n; i++) {
		if(i != p[0] && i != p[1] && qry(p[0], p[1], i) == i) {
			std::cout << "! " << i+1 << std::endl;
			return 0;
		}
	}
	// let's go?
	assert(0);
}