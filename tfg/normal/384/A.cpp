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
	std::vector<std::string> a(n, std::string(n, '.'));
	int ans = 0;
	for(int i = 0; i < n; i += 2) {
		for(int j = 0; j < n; j += 2) {
			ans++;
			a[i][j] = 'C';
		}
	}
	for(int i = 1; i < n; i += 2) {
		for(int j = 1; j < n; j += 2) {
			ans++;
			a[i][j] = 'C';
		}
	}
	std::cout << ans << '\n';
	for(auto str : a) {
		std::cout << str << '\n';
	}
}