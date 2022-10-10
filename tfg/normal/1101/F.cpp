#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

int a[505];
int s[ms], f[ms], r[ms], p[ms];
long long c[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> s[i] >> f[i] >> c[i] >> r[i];
		p[i] = i;
	}
	std::shuffle(p, p + m, rng);
	auto simul = [&](int j, long long tot) {
		long long cur = tot;
		int got = 0;
		for(int i = s[j]-1; i < f[j]-1; i++) {
			//std::cout << "visiting " << i << " to " << i + 1 << "\n";
			if((long long) c[j] * (a[i+1] - a[i]) > cur) {
				cur = tot;
				got++;
			}
			if((long long) c[j] * (a[i+1] - a[i]) > tot) {
				return false;
			}
			cur -= c[j] * (a[i+1] - a[i]);
		}
		//std::cout << "for " << j << ", " << tot << " got " << got << "\n";
		return got <= r[j];
	};
	long long ans = 0;
	for(int i = 0; i < m; i++) {
		if(simul(p[i], ans)) continue;
		long long rr = 1e18;
		while(ans != rr) {
			long long mid = (ans + rr) / 2;
			if(simul(p[i], mid)) {
				rr = mid;
			} else {
				ans = mid + 1;
			}
		}
		//std::cout << "solved for " << p[i] << ", got " << ans << "\n"
		assert(simul(p[i], ans));
	}
	std::cout << ans << '\n';
}