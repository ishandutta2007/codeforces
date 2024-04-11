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
	std::vector<std::string> mat(n);
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	std::vector<std::vector<int>> up(n+1, std::vector<int>(m+1, 0));
	auto right = up;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mat[i][j] == '.') {
		if(i+1 < n && mat[i][j] == mat[i+1][j]) {
			up[i+1][j+1]++;
		}
		if(j+1 < m && mat[i][j] == mat[i][j+1]) {
			right[i+1][j+1]++;
		}
	}
	auto go = [&](auto &kek) {
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) kek[i][j] = kek[i][j] + kek[i-1][j] + kek[i][j-1] - kek[i-1][j-1];
	};
	go(right), go(up);
	int q;
	std::cin >> q;
	auto qry = [](auto &sum, int x0, int x1, int y0, int y1) {
		//std::cout << "qry [" << x0 << ", " << x1 << "), [" << y0 << ", " << y1 << ") = " << sum[x1][y1] - sum[x1][y0] - sum[x0][y1] + sum[x0][y0] << "\n";
		return sum[x1][y1] - sum[x1][y0] - sum[x0][y1] + sum[x0][y0];
	};
	while(q--) {
		int r[2], c[2];
		std::cin >> r[0] >> c[0] >> r[1] >> c[1];
		std::cout << qry(up, r[0]-1, r[1]-1, c[0]-1, c[1]) + qry(right, r[0]-1, r[1], c[0]-1, c[1]-1) << '\n';
	}
}