#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;
const int bs = 100;

double dp[ms][bs];
int par[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	int n = 1;
	for(int i = 0; i < bs; i++) {
		dp[0][i] = 1;
	}
	par[0] = -1;
	std::cout << std::fixed << std::setprecision(10);
	while(q--) {
		char ch;
		int u;
		std::cin >> ch >> u;
		u--;
		if(ch == '1') {
			for(int i = 0; i < bs; i++) {
				dp[n][i] = 1;
			}
			par[n++] = u;
			int v = u;
			int h = 0;
			double prv = 1, nxt = 0.5;
			while(h < bs && v != -1) {
				double kek = (1 + dp[v][h]) / 2;
				dp[v][h] *= nxt / prv;
				nxt = (1 + dp[v][h]) / 2;
				prv = kek;
				h++;
				v = par[v];
			}
		} else {
			double ans = 0;
			for(int i = 1; i < bs; i++) {
				ans += i * (dp[u][i] - dp[u][i-1]);
			}
			std::cout << ans << '\n';
		}
	}
}