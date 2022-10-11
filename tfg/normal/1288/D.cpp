#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
	}
	int l = 0, r = 1e9;
	auto check = [&](int x) {
		std::vector<int> b(1 << m, -1);
		for(int i = 0; i < n; i++) {
			int mask = 0;
			for(int j = 0; j < m; j++) {
				if(a[i][j] >= x) {
					mask |= 1 << j;
				}
			}
			b[mask] = i;
		}
		for(int len = 1; len < (1 << m); len += len) {
			for(int i = 0; i < (1 << m); i += 2 * len) {
				for(int j = 0; j < len; j++) {
					b[i+j] = std::max(b[i+j], b[i+j+len]);
				}
			}
		}
		for(int i = 0; i < (1<<m); i++) {
			int j = i ^ ((1<<m)-1);
			if(std::min(b[i], b[j]) >= 0) {
				return std::pair<int, int>(b[i], b[j]);
			}
		}
		return std::pair<int, int>(-1, -1);
	};
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(check(mid).first != -1) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	auto ans = check(l);
	std::cout << ans.first+1 << ' ' << ans.second+1 << std::endl;
}