#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		int cost = 1e9;
		int ans[3] = {1, 1, 1};
		for(int i = 1; i <= 20000; i++) {
			for(int j = i; j <= 20000; j += i) {
				int k = c / j * j;
				if(k < j) k = j;
				if(k < c && c - k > k+j - c) {
					k += j;
				}
				int cur = abs(i-a) + abs(j-b) + abs(k-c);
				if(cur < cost) {
					cost = cur;
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
				}
			}
		}
		std::cout << cost << '\n';
		std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
	}
}