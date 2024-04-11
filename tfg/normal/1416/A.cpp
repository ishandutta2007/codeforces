#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> pos(n+1);
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			pos[x].push_back(i);
		}
		const int INF = 1e9;
		std::vector<int> ans(n+1, INF);
		for(int i = 1; i <= n; i++) {
			int last = -1;
			int got = 1;
			pos[i].push_back(n);
			for(auto x : pos[i]) {
				got = std::max(got, x - last);
				last = x;
			}
			if(got <= n) {
				ans[got] = std::min(ans[got], i);
			}
		}
		for(int i = 1; i <= n; i++) {
			ans[i] = std::min(ans[i], ans[i-1]);
			std::cout << (ans[i] == INF ? -1 : ans[i]) << (i == n ? '\n' : ' ');
		}
	}
}