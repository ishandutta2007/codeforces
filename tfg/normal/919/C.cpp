#include <iostream>
#include <cstdio>

const int ms = 2020;

char mat[ms][ms];

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		scanf(" %s", mat[i]);
	}
	for(int i = 0; i < n; i++) {
		int cur = 0;
		for(int j = 0; j < m; j++) {
			int t = mat[i][j] == '.';
			if(t) {
				cur++;
			} else {
				ans += std::max(0, cur - k + 1);
				cur = 0;
			}
		}
		if(cur >= k) {
			ans += cur - k + 1;
		}
	}
	for(int i = 0; i < m; i++) {
		int cur = 0;
		for(int j = 0; j < n; j++) {
			int t = mat[j][i] == '.';
			if(t) {
				cur++;
			} else {
				ans += std::max(0, cur - k + 1);
				cur = 0;
			}
		}
		if(cur >= k) {
			ans += cur - k + 1;
		}
	}
	if(k == 1) {
		ans /= 2;
	}
	std::cout << ans << '\n';
}