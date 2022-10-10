#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int n;
std::pair<int, int> tree[2 * ms];

void upd(int l, int r, std::pair<int, int> v) {
	for(l += n, r += n; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			tree[l] = std::max(tree[l], v);
			l++;
		}
		if(r & 1) {
			r--;
			tree[r] = std::max(tree[r], v);
		}
	}
}

long long dp[202][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		tree[n+i] = std::pair<int, int>(0, i + 1);
		tree[i] = std::pair<int, int>(-1, -1);
	}
	for(int i = 0; i < k; i++) {
		int s, t, d, w;
		std::cin >> s >> t >> d >> w;
		s--;
		upd(s, t, std::pair<int, int>(w, d));
	}
	for(int i = 1; i < n; i++) {
		tree[i+i] = std::max(tree[i+i], tree[i]);
		tree[i+i+1] = std::max(tree[i+i+1], tree[i]);
	}
	for(int i = 0; i < n; i++) {
		//std::cout << i << ": (" << tree[n+i].first << ", " << tree[n+i].second << ")\n";
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	long long ans = 1e18;
	for(int j = 0; j <= m; j++) {
		for(int i = 0; i < n; i++) {
			std::pair<int, int> to = tree[i + n];
			std::swap(to.first, to.second);
			dp[j][to.first] = std::min(dp[j][to.first], dp[j][i] + to.second);
			if(j + 1 <= m) {
				dp[j+1][i+1] = std::min(dp[j+1][i+1], dp[j][i]);
			}
		}
		ans = std::min(ans, dp[j][n]);
	}
	std::cout << ans << '\n';
}