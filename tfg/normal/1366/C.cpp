#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::map<int, int>> a(n+m-1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int x;
				std::cin >> x;
				int v[2] = {i+j, n+m-2-(i+j)};
				if(v[0] != v[1]) {
					a[std::min(v[0], v[1])][x]++;
				}
			}
		}
		int ans = 0;
		for(auto mp : a) {
			int sum = 0;
			int mx = 0;
			for(auto it : mp) {
				sum += it.second;
				mx = std::max(mx, it.second);
			}
			ans += sum - mx;
		}
		std::cout << ans << '\n';
	}
}