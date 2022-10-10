#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > mat(n, std::vector<int>(m, 0));
	std::vector<std::vector<int> > dp(m+1, std::vector<int>(m+1, 0));
	for(int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for(int j = 0; j < m; j++) {
			char c = str[j];
			mat[i][j] = c - '0';
		}
		for(int l = 0, r = 0; l < m; l = r) {
			while(r < m && mat[i][l] == mat[i][r]) r++;
			//std::cout << "got range [" << l << ", " << r << "), " << mat[i][l] << "\n";
			if(mat[i][l] == 1) {
				//std::cout << "range [" << l << ", " << r << ")\n";
				dp[l][r]++;
			}
		}
	}
	for(int i = 0; i <= m; i++) {
		for(int j = m-1; j >= 0; j--) {
			dp[i][j] += dp[i][j+1];
		}
	}
	for(int j = 0; j <= m; j++) {
		for(int i = 1; i <= m; i++) {
			dp[i][j] += dp[i-1][j];
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; i++) {
		for(int j = i + 1; j <= m; j++) {
			ans = std::max(ans, dp[i][j] * (j - i));
		}
	}
	std::cout << ans << '\n';
}