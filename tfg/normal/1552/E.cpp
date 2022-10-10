#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> lst(n, -1), pos(n, -1);
	std::vector<std::pair<int, int>> ans(n, {-1, -1});
	int cur = 0;
	int lim = (n + (k-1) - 1) / (k-1);
	for(int i = 0; i < n * k; i++) {
		int x;
		std::cin >> x;
		x--;
		if(ans[x].first != -1) continue;
		if(lst[x] == -1 || cur - lst[x] >= lim) {
			lst[x] = cur;
			pos[x] = i;
		} else {
			ans[x] = std::pair<int, int>(pos[x], i);
			cur++;
		}
	}
	assert(cur == n);
	for(int i = 0; i < n; i++) {
		std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	}
}