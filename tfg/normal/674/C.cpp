#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const double INF = 1e30;
const int ms = 200200;

long long t[ms];
double sum[2][ms];

double f(int l, int r) {
	return sum[0][r+1] - sum[0][l] - (double) t[l] * (sum[1][r+1] - sum[1][l]);
}

void solve(std::vector<double> &dp, std::vector<double> &nxt, int l, int r, int optl, int optr) {
	if(l > r) return;
	int mid = (l + r) / 2;
	int opt = -1;
	for(int i = optl; i < mid && i <= optr; i++) {
		if(nxt[mid] > dp[i] + f(i, mid-1)) {
			nxt[mid] = dp[i] + f(i, mid-1);
			opt = i;
		}
	}
	assert(opt != -1);
	solve(dp, nxt, l, mid-1, optl, opt);
	solve(dp, nxt, mid+1, r, opt, optr);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> t[i+1];
		t[i+1] += t[i];
		sum[0][i+1] = sum[0][i] + (double) t[i+1] / (t[i+1] - t[i]);
		sum[1][i+1] = sum[1][i] + (double) 1.0 / (t[i+1] - t[i]);
	}
	std::vector<double> dp(n+1, INF);
	dp[0] = 0;
	for(int i = 1; i <= k; i++) {
		std::vector<double> nxt(n+1, INF);
		/*for(int l = 0; l < n; l++) {
			double cur = dp[l];
			for(int r = l; r < n; r++) {
				// probability of getting this one right is
				// (t[r+1]-t[r]) / (t[r+1]-t[l])
				cur += (double) (t[r+1]-t[l]) / (t[r+1]-t[r]);
				// f(l, r) = sum [l, r] of (t[i+1]-t[l]) / (t[i+1]-t[i])
				nxt[r+1] = std::min(nxt[r+1], cur);
			}
		}*/
		solve(dp, nxt, i, n, 0, n);
		nxt.swap(dp);
	}
	std::cout << std::fixed << std::setprecision(10) << dp.back() << '\n';
}