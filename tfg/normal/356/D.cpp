#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 70070;
	int n, s;
	std::cin >> n >> s;
	std::vector<int> a(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	const int bs = 300;
	std::vector<std::bitset<ms>> dps;
	std::bitset<ms> dp;
	dp[0] = 1;
	for(int i = 0; i + 1 < n; i++) {
		if(i % bs == 0) {
			dps.push_back(dp);
		}
		dp = dp | (dp << a[p[i]]);
	}
	std::vector<int> use(n, -1);
	s -= a[p[n-1]];
	if(s < 0 || !dp[s]) {
		std::cout << "-1\n";
		return 0;
	}
	//std::cout << "got " << s << '\n';
	/*for(int i = n-2; i >= 0; i--) {
		if(!dp[i][s]) {
			s -= a[p[i]];
		} else {
			use[p[i+1]] = p[i];
		}
	}*/
	int l = n-2, r = n-2;
	std::vector<std::bitset<ms>> wtf(bs);
	while(l >= 0) {
		if(l % bs == 0) {
			dp = dps.back();
			dps.pop_back();
			for(int i = l; i <= r; i++) {
				wtf[i % bs] = dp;
				dp = dp | (dp << a[p[i]]);
			}
			for(int i = r; i >= l; i--) {
				if(!wtf[i%bs][s]) {
					s -= a[p[i]];
				} else {
					use[p[i+1]] = p[i];
				}
			}
			r = l - 1;
		}

		l--;
	}
	//std::cout << "got " << s << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << a[i] - (use[i] != -1 ? a[use[i]] : 0) << ' ';
		if(use[i] != -1) {
			std::cout << "1 " << use[i] + 1 << '\n';
		} else {
			std::cout << "0\n";
		}
	}
}