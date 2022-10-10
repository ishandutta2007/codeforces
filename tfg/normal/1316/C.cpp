#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, p;
	std::cin >> n >> m >> p;
	std::vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	int i = n-1, j = m-1;
	while(i>=0 && a[i] % p == 0) i--;
	while(j>=0 && b[j] % p == 0) j--;
	assert(i >=0 && j >= 0);
	std::cout << i+j << '\n';
}