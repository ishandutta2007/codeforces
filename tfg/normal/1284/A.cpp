#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n), b(m);
	for(auto &s : a) std::cin >> s;
	for(auto &s : b) std::cin >> s;
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		std::cin >> x;
		x--;
		std::cout << a[x % n] + b[x % m] << '\n';
	}
}