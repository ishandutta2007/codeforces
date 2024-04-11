#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MAGIC = 300;
const int ms = 100;

int n;
double memo[MAGIC][ms][ms];

double dp(int k, int i, int j) {
	if(k == 0) return i > j ? 1.0 : 0.0;
	double &ans = memo[k][i][j];
	if(ans > -0.5) return ans;
	ans = 0;
	for(int l = 0; l < n; l++) {
		for(int r = l; r < n; r++) {
			ans += dp(k-1, l <= i && i <= r ? l + (r - i) : i, l <= j && j <= r ? l + (r - j) : j);
		}
	}
	return ans = ans / (n * (n + 1) / 2);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < MAGIC; i++) {
		for(int j = 0; j < ms; j++) {
			for(int k = 0; k < ms; k++) {
				memo[i][j][k] = -1;
			}
		}
	}
	int k;
	std::cin >> n >> k;
	k = std::min(k, MAGIC - 1);
	std::cout << std::fixed << std::setprecision(10);
	double ans = 0;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i] < a[j]) {
				ans += dp(k, i, j);
			}
		}
	}
	std::cout << ans << '\n';
}