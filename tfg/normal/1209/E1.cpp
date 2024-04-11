#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int a[2020][12];

void solve() {
	int n, m;
	std::cin >> m >> n;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i < n; i++) {
			std::cin >> a[i][j];
		}
	}
	std::vector<int> ans(1 << m, 0);
	for(int i = 0; i < n; i++) {
		std::vector<int> trans(1 << m, 0);
		for(int mask = 1; mask < (1 << m); mask++) {
			int sum = 0;
			for(int j = 0; j < m; j++) {
				if(mask & (1 << j)) {
					sum += a[i][j];
				}
			}
			int x = mask;
			for(int j = 0; j < m; j++) {
				trans[x] = std::max(trans[x], sum);
				x = (x >> 1) | ((x&1) << (m-1));
			}
		}
		std::vector<int> nxt = trans;
		for(int mask = 0; mask < (1 << m); mask++) {
			int lol = mask ^ ((1<<m)-1);
			for(int j = lol; j > 0; j = (j-1) & lol) {
				//assert((j & mask) == 0);
				nxt[j|mask] = std::max(nxt[j|mask], ans[j] + trans[mask]);
			}
		}
		ans.swap(nxt);
	}
	std::cout << ans.back() << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}