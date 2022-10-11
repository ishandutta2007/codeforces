#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::set<std::pair<int, int>> used;
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
			a[i][j]--;
		}
	}
	auto test = [&](int x, int y) {
		bool valid = true;
		for(int i = 0; i < n; i++) {
			int lol = 0;
			std::swap(a[i][x], a[i][y]);
			for(int j = 0; j < m; j++) {
				if(a[i][j] != j) {
					lol++;
				}
			}
			std::swap(a[i][x], a[i][y]);
			if(lol > 2) {
				valid = false;
			}
		}
		return valid;
	};
	
	for(int i = 0; i < m; i++) {
		for(int j = (i==0?0:i+1); j < m; j++) {
			if(test(i, j)) {
				std::cout << "YES\n";
				return 0;
			}
		}
	}
	std::cout << "NO\n";
}