#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b;
	std::cin >> n >> a >> b;
	bool inv = false;
	if(a < b) {
		std::swap(a, b);
		inv = true;
	}
	if(b > 1 || (a == 1 && b == 1 && (n == 2 || n == 3))) {
		std::cout << "NO\n";
		return 0;
	}
	if(n == 1) {
		std::cout << "YES\n0\n";
		return 0;
	}
	std::cout << "YES\n";
	std::vector<std::string> ans(n, std::string(n, '0'));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i <= n - a && j <= n - a) {
				ans[i][j] = '1';
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(inv) {
				ans[i][j] -= '0';
				ans[i][j] = 1 - ans[i][j];
				ans[i][j] += '0';
			}
			if(i == j) {
				ans[i][j] = '0';
			}
		}
	}
	if(a == 1 && b == 1) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				ans[i][j] = '0';
			}
			if(i + 1 < n) {
				ans[i][i + 1] = '1';
			}
			if(i > 0) {
				ans[i][i - 1] = '1';
			}
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << std::endl;
	}
}