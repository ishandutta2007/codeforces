#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		int f[2] = {0, 0};
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			a[i] %= 2;
			f[a[i]]++;
		}
		const long long INF = 1e18;
		long long ans = INF;
		for(int rep = 0; rep < 2; rep++) {
			if(f[rep] == f[1-rep] || f[rep] == 1 + f[1-rep]) {
				int wtf[2] = {0, 0};
				long long cur = 0;
				for(int i = 0; i < n; i++) {
					if(wtf[0] == wtf[1]) {
						if(a[i] == (rep + i) % 2) {
							continue;
						} else {
							wtf[a[i]]++;
						}
					} else if(wtf[a[i]]) {
						wtf[a[i]]++;
					} else {
						assert(wtf[1-a[i]] > 0);
						cur += wtf[1-a[i]]--;
					}
				}
				ans = std::min(ans, cur);
			}
		}
		std::cout << (ans >= INF ? -1LL : ans) << '\n';
	}
}