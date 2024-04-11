#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1.1e9;

char qc[20];
int qt[20];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<int>());
	int m;
	std::cin >> m;
	while((int) a.size() > m) a.pop_back();
	n = (int) a.size();
	std::vector<int> dp(1 << n, 0);
	for(int i = m-1; i >= 0; i--) {
		std::cin >> qc[i];
		std::cin >> qt[i];
	}
	for(int i = 0; i < m; i++) {
		char c;
		int t;
		//std::cin >> c >> t;
		c = qc[i];
		t = qt[i];
		//std::cout << "solving " << c << ", " << t << "\n";
		if(t == 1) {
			if(c == 'p') {
				for(int j = 0; j < (1 << n); j++) {
					for(int k = 0; k < n; k++) {
						if(((j >> k) & 1) == 0) {
							dp[j] = std::max(dp[j | (1 << k)] + a[k], dp[j]);
						}
					}
				}
			} else {
				for(int j = 0; j < (1 << n); j++) {
					for(int k = 0; k < n; k++) {
						if(((j >> k) & 1) == 0) {
							dp[j] = std::max(dp[j | (1 << k)], dp[j]);
						}
					}
				}
			}
		} else {
			if(c == 'p') {
				for(int j = 0; j < (1 << n); j++) {
					for(int k = 0; k < n; k++) {
						if(((j >> k) & 1) == 0) {
							dp[j] = std::min(dp[j | (1 << k)] - a[k], dp[j]);
						}
					}
				}
			} else {
				for(int j = 0; j < (1 << n); j++) {
					for(int k = 0; k < n; k++) {
						if(((j >> k) & 1) == 0) {
							dp[j] = std::min(dp[j | (1 << k)], dp[j]);
						}
					}
				}
			}
		}
	}
	std::cout << dp[0] << '\n';
}