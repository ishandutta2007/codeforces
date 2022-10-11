#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <utility>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 404;

int a[ms][ms];
std::pair<int, int> prv[ms][ms];
std::pair<int, int> first[ms * ms];
int dp[ms][ms][ms]; // [linha][l][r]
int to[ms];

void process(std::pair<int, int> cur) {
	memset(to, 0x3f, sizeof to);
	while(cur.first != -1) {
		for(int j = 0; j < ms; j++) {
			if(j <= cur.second) {
				dp[cur.first][j][cur.second] = std::min(dp[cur.first][j][cur.second], to[j]);
			} else {
				dp[cur.first][cur.second][j] = std::min(dp[cur.first][cur.second][j], to[j]);
			}
		}
		to[cur.second] = cur.first;
		cur = prv[cur.first][cur.second];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < ms * ms; i++) {
		first[i] = {-1, -1};
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[i][j];
			prv[i][j] = first[a[i][j]];
			first[a[i][j]] = {i, j};
		}
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i = 0; i < ms * ms; i++) {
		if(first[i].first != -1) {
			process(first[i]);
		}
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < m; j++) {
			dp[i][j][j] = std::min(dp[i][j][j], dp[i+1][j][j]);
			if(dp[i][j][j] > (int) 1e9) {
				ans = std::max(ans, n - i);
			} else {
				ans = std::max(dp[i][j][j] - i, ans);
			}
		}
		for(int s = 2; s <= m; s++) {
			for(int l = 0; l + s <= m; l++) {
				int r = l + s - 1;
				dp[i][l][r] = std::min(dp[i][l][r], std::min(dp[i][l+1][r], dp[i][l][r-1]));
				dp[i][l][r] = std::min(dp[i][l][r], dp[i+1][l][r]);
				//std::cout << "trying (" << i << ", " << l << ", " << r << ")\n";
				if(dp[i][l][r] > (int) 1e9) {
					ans = std::max(ans, (r - l + 1) * (n - i));
					//std::cout << "got " << (r - l + 1) * (n - i) << std::endl;
				} else {
					ans = std::max(ans, (r - l + 1) * (dp[i][l][r] - i));
					//std::cout << "got " << (r - l + 1) * (dp[i][l][r] - i) << std::endl;
				}
			}
		}
	}
	std::cout << ans << std::endl;
}