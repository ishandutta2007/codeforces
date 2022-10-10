#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(auto &v : a) { std::cin >> v; }
	auto b = a;
	std::sort(b.begin(), b.end());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += a[i] != b[i];
	}
	std::cout << (ans <= 2 ? "YES\n" : "NO\n");
}