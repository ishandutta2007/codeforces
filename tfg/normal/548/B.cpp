#include <iostream>

int a[505][505];

int solve(int* b, int n) {
	int ans = 0;
	int cur = 0;
	for(int i = 0; i < n; i++) {
	    //std::cout << b[i] << ' ';
		if(b[i] == 1) {
			cur++;
		} else {
			cur = 0;
		}
		ans = std::max(ans, cur);
	}
	//std::cout << ans << '\n';
	return ans;
}

int ans[505];

int main() {
	int n, m, q;
	std::cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
		}
		ans[solve(a[i], m)]++;
	}
	while(q--) {
		int i, j;
		std::cin >> i >> j;
		i--;j--;
		ans[solve(a[i], m)]--;
		a[i][j] ^= 1;
		ans[solve(a[i], m)]++;
		int got = 0;
		for(int ii = 0; ii < 505; ii++) {
			if(ans[ii]) {
				got = ii;
			}
		}
		std::cout << got << '\n';
	}
}