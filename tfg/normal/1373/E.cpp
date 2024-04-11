#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gen(int sum) {
	if(sum < 10) return sum;
	else return gen(sum - 9) * 10 + 9;
}

long long gen2(int sum) {
	if(sum < 9) {
		return sum;
	} else {
		return gen(sum - 8) * 10 + 8;
	}
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	const long long INF = 1e18;
	long long ans = INF;
	for(int i = 0; i < 10; i++) {
		if(i + k < 10) {
			int got = (i + (i + k)) * (k + 1) / 2;
			int want = n - got;
			if(want >= 0 && want % (k+1) == 0) {
				ans = std::min(ans, gen(want / (k+1)) * 10 + i);
			}
		} else {
			int got = (i + (i + k)) * (k + 1) / 2;
			int r = k + i - 9;
			got -= 10 * r;
			long long wtf = 0, ha = 1;
			for(int carries = 1; carries <= 18; carries++) {
				// got + k * sum - r * carries * 9 + r == n
				// k * sum == n - got + r * carries * 9 - r
				int want = n - got + r * (carries - 1) * 9 - r;
				//std::cout << "for " << i << ", " << carries << " got " << n << " - " << got << " + " << r << " * " << carries << " * " << 9 << " - " << r << '\n';
				if(want >= 0 && want % (k + 1) == 0) {
					int sum = want / (k + 1);
					if(sum >= (carries - 1) * 9) {
						long long val = gen2(sum - (carries - 1) * 9);
						if(val == 0 || INF / val / ha / 10 != 0) {
							ans = std::min(ans, (val * ha + wtf) * 10 + i);
						}
					}
				}
				wtf = wtf * 10 + 9;
				ha = ha * 10;
			}
		}
	}
	if(ans == INF) {
		ans = -1;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}