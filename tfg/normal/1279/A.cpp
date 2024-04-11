#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int a[3];
		std::cin >> a[0] >> a[1] >> a[2];
		std::sort(a, a + 3);
		std::cout << (((long long) a[0] + a[1] + a[2] + 1) / 2 >= a[2] ? "Yes\n" : "No\n");
	}
}