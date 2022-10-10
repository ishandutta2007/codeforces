#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n+1, std::vector<int>(m+1, 0));
	auto row = a;
	auto col = a;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char ch;
			std::cin >> ch;
			a[i][j] = ch == '0';
		}
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			row[i][j] = a[i][j] ? 1 + row[i][j+1] : 0;
			col[i][j] = a[i][j] ? 1 + col[i+1][j] : 0;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!a[i][j]) continue;
			int mask = 15;
			for(int d = 1; mask; d++) {
				if(!(i+d < n && j+d < m && a[i+d][j+d])) {
					mask &= ~1;
				}
				if(!(i+d < n && j-d >= 0 && a[i+d][j-d])) {
					mask &= ~2;
				}
				if(!(i-d >= 0 && j-d >= 0 && a[i-d][j-d])) {
					mask &= ~4;
				}
				if(!(i-d >= 0 && j+d < m && a[i-d][j+d])) {
					mask &= ~8;
				}
				if((mask & 1) && row[i][j] > d && col[i][j+d] > d) {
					ans++;
				}
				if((mask & 2) && row[i+d][j-d] > d && col[i][j] > d) {
					ans++;
				}
				if((mask & 4) && row[i][j-d] > d && col[i-d][j-d] > d) {
					ans++;
				}
				if((mask & 8) && row[i-d][j] > d && col[i-d][j] > d) {
					ans++;
				}
				if((mask & 9) == 9 && col[i-d][j+d] >= 2 * d) {
					ans++;
				}
				if((mask & 3) == 3 && row[i+d][j-d] >= 2 * d) {
					ans++;
				}
				if((mask & 6) == 6 && col[i-d][j-d] >= 2 * d) {
					ans++;
				}
				if((mask & 12) == 12 && row[i-d][j-d] >= 2 * d) {
					ans++;
				}
			}
		}
	}
	std::cout << ans << '\n';
}