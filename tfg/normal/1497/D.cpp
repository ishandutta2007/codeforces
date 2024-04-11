#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

int n;
int score[ms], tag[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::cin >> n;
		for(int i = 0; i < n; i++) std::cin >> tag[i];
		for(int i = 0; i < n; i++) std::cin >> score[i];
		long long ans = 0;
		std::vector<long long> dp1(n, 0), dp0(n, 0);
		// 1 has fixed r, variable l
		// 0 has fixed l, variable r
		for(int r = n-1; r >= 0; r--) {
			// first calculate <1>(l, r)
			std::vector<long long> nxt1(n, 0);
			for(int l = 0; l <= r; l++) {
				if(l) nxt1[l] = nxt1[l-1];
				else nxt1[l] = dp0[r];
				if(tag[l] != tag[r]) {
					nxt1[l] = std::max(nxt1[l], (long long) dp0[l] + std::abs(score[l] - score[r]));
				}
			}
			// then  calculate <0>(l, r)
			std::vector<long long> nxt0(n, 0);
			for(int l = 0; l <= r; l++) {
				nxt0[l] = dp0[l];
				if(tag[l] != tag[r]) {
					nxt0[l] = std::max(nxt0[l], (long long) (l == 0 ? dp0[r] : nxt1[l-1]) + std::abs(score[l] - score[r]));
				}
			}
			nxt0.swap(dp0);
			nxt1.swap(dp1);
			ans = std::max(ans, dp1[r]);
			assert(dp1[r] >= dp0[r]);
		}
		std::cout << ans << '\n';
	}
}