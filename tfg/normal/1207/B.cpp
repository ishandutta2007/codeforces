#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
	auto b = a;
	std::vector<std::pair<int, int>> ans;
	auto op = [&](int i, int j) {
		ans.emplace_back(i+1, j+1);
		b[i][j] = b[i+1][j+1] = b[i][j+1] = b[i+1][j] = 1;
	};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	for(int i = 0; i+1 < n; i++) {
		for(int j = 0; j+1 < m; j++) {
			if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
				op(i, j);
			}
		}
	}
	if(a == b) {
		std::cout << ans.size() << '\n';
		for(auto p : ans) std::cout << p.first << ' ' << p.second << std::endl;
	} else {
		std::cout << "-1\n";
	}
}