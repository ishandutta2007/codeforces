#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 505;

int dist[ms][ms];
int wtf[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> dist[i][j];
		}
	}
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> p[n-i-1];
		p[n-i-1]--;
	}
	std::vector<long long> haha(n);
	for(int k = 0; k < n; k++) {
		long long ans = 0;
		memset(wtf, 0x3f, sizeof wtf);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				wtf[i][j] = std::min(dist[i][j], dist[i][p[k]] + dist[p[k]][j]);
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j  = 0; j < n; j++) {
				if(i <= k && j <= k) {
					ans += wtf[p[i]][p[j]];
				}
				dist[i][j] = wtf[i][j];
			}
		}
		haha[n-k-1] = ans;
	}
	for(int i = 0; i < n; i++) {
		std::cout << haha[i] << (i + 1 == n ? '\n' : ' ');
	}
}