#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::string ans;
	int size = 1 + (n - k) / 2;
	for(int i = 0; i < n; i++) {
		ans += i % size == size - 1 ? '1' : '0';
	}
	std::cout << ans << '\n';
}