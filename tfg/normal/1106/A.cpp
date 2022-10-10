#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::string> mat(n);
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		//std::cout << mat[i] << '\n';
	}
	int ans = 0;
	for(int i = 1; i + 1 < n; i++) {
		for(int j = 1; j + 1 < n; j++) {
			if(mat[i][j] == 'X' && mat[i+1][j+1] == 'X' && mat[i+1][j-1] == 'X' && mat[i-1][j+1] == 'X' && mat[i-1][j-1] == 'X') {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}