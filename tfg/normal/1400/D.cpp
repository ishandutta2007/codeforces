#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int buffer[5050];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> a(n);
		std::vector<int> b(n);
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			x--;
			b[i] = x;
			a[x].push_back(i);
		}
		long long ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i == j) {
					long long x = (long long) a[i].size();
					ans += x * (x - 1) * (x - 2) * (x - 3) / 24;
				} else {
					std::merge(a[i].begin(), a[i].end(), a[j].begin(), a[j].end(), buffer);
					long long dp[5] = {1, 0, 0, 0, 0};
					for(int id = 0; id < (int) a[i].size() + (int) a[j].size(); id++) {
						if(b[buffer[id]] == i) {
							dp[1] += dp[0];
							dp[3] += dp[2];
						} else {
							dp[2] += dp[1];
							dp[4] += dp[3];
						}
					}
					ans += dp[4];
				}
			}
		}
		std::cout << ans << '\n';
	}
}