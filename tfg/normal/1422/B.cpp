#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::vector<int>> a(n, std::vector<int>(m));
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				std::cin >> a[i][j];
			}
		}
		for(int i = 0; i < (n + 1) / 2; i++) {
			for(int j = 0; j < (m + 1) / 2; j++) {
				std::vector<int> got(1, a[i][j]);
				if(n - i - 1 != i) {
					got.push_back(a[n-i-1][j]);
					if(m - j - 1 != j) {
						got.push_back(a[n-i-1][m-j-1]);
					}
				}
				if(m - j - 1 != j) {
					got.push_back(a[i][m-j-1]);
				}
				std::sort(got.begin(), got.end());
				for(auto val : got) ans += abs(val - got[(int) got.size() / 2]);
			}
		}
		std::cout << ans << '\n';
	}
}