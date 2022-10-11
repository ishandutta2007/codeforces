#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a[] = {0, 0}, b[] = {0, 0};
	int n, m;
	std::cin >> n >> m;
	while(n--) {
		int x;
		std::cin >> x;
		a[x % 2]++;
	}
	while(m--) {
		int x;
		std::cin >> x;
		b[(x+1) % 2]++;
	}
	std::cout << std::min(a[0], b[0]) + std::min(a[1], b[1]) << '\n';
}