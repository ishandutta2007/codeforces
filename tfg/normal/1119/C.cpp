#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> row(n, 0), col(m, 0);
	for(int rep = 0; rep < 2; rep++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				std::cin >> x;
				row[i] ^= x;
				col[j] ^= x;
			}
		}
	}
	bool ans = true;
	for(auto v : row) ans = ans && v == 0;
	for(auto v : col) ans = ans && v == 0;
	std::cout << (ans ? "Yes\n" : "No\n");
}