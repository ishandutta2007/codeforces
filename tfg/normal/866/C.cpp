#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 55;
const double INF = 1e18;

bool visit[ms][ms * 100];
double memo[ms][ms * 100];
double mid;
int n, R;
double p[ms];
int f[ms], s[ms];
double dp(int on, int sum) {
	double &ans = memo[on][sum];
	if(sum > R) return mid;
	if(on == n) return 0;
	if(visit[on][sum]) return ans;
	visit[on][sum] = true;
	return ans = std::min(mid, (dp(on+1, sum+f[on]) + f[on]) * p[on] + (dp(on+1, sum+s[on]) + s[on]) * (1 - p[on]));
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> R;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> f[i] >> s[i] >> x;
		p[i] = x / 100.0;
	}
	double l = 0, r = 1e9;
	for(int rep = 0; rep < 70; rep++) {
		mid = (l + r) / 2;
		memset(visit, false, sizeof visit);
		if((dp(1, f[0]) + f[0]) * p[0] + (dp(1, s[0]) + s[0]) * (1 - p[0]) > mid + 1e-9) {
			l = mid;
		} else {
			r = mid;
		}
	}
	std::cout << std::fixed << std::setprecision(10) << (l+r)/2 << '\n';
}