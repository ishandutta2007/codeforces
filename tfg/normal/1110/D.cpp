#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const long long INF = 1e18;

long long dp[ms][3][3];
int f[ms];


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		f[v]++;
	}
	for(int i = 0; i < ms; i++) {
		int a = f[i];
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(j + k > a) {
					dp[i][j][k] = -INF;
					//std::cout << "skipping at " << i << ", " << j << ", " << k << "\n";
					continue;
				}
				for(int l = 0; l < 3 && j + k + l <= a; l++) {
					dp[i+1][k][l] = std::max(dp[i+1][k][l], dp[i][j][k] + l + (a - j - k - l) / 3);
				}
			}
		}
	}
	std::cout << dp[ms-1][0][0] << '\n';
}