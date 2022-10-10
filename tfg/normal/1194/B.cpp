#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> rows(n, 0), cols(m, 0), pos(n * m, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char c;
				std::cin >> c;
				if(c == '.') {
					rows[i]++;
					cols[j]++;
					pos[i*m+j]++;
				}
			}
		}
		int ans = n + m - 1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				ans = std::min(ans, rows[i] + cols[j] - pos[i*m+j]);
			}
		}
		std::cout << ans << '\n';
	}
}