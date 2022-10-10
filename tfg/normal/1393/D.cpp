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
	std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
	std::vector<std::string> mat(n);
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	auto b = a;
	for(int i = 0; i < n; i++) {
		for(int j = m-1; j >= 0; j--) {
			a[i][j] = j + 1 == m || mat[i][j] != mat[i][j+1] ? 1 : 1 + a[i][j+1];
		}
		b[i] = a[i];
	}
	for(int i = 0; i < m; i++) {
		a[0][i] = b[n-1][i] = 1;
	}
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(j + 1 != m) {
				a[i][j] = std::min(a[i][j], mat[i][j] == mat[i-1][j+1] ? 2 + a[i-1][j+1] : 1);
			}
		}
	}
	for(int i = n-2; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			if(j + 1 != m) {
				b[i][j] = std::min(b[i][j], mat[i][j] == mat[i+1][j+1] ? b[i+1][j+1] + 2 : 1);
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			ans += (std::min(a[i][j], b[i][j]) + 1) / 2;
		}
	}
	std::cout << ans << '\n';
}