#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

std::string mat[ms];
int dp[ms][ms];
std::vector<std::pair<int, int>> dist[ms + ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
		for(int j = 0; j < n; j++) {
			dist[i+j].emplace_back(i, j);
		}
	}
	if(k > 0 && mat[0][0] > 'a') {
		mat[0][0] = 'a';
		k--;
	}
	std::string ans;
	ans += mat[0][0];
	for(int d = 1; dist[d].size() > 0; d++) {
		int mn[26];
		for(int j = 0; j < 26; j++) {
			mn[j] = (int) 1e8;
		}
		for(auto pos : dist[d]) {
			int x, y;
			int ox = pos.first, oy = pos.second;
			dp[ox][oy] = (int) 1e9;
			x = pos.first, y = pos.second - 1;
			if(x >= 0 && y >= 0) {
				dp[ox][oy] = std::min(dp[ox][oy], dp[x][y]);
			}
			y++;x--;
			if(x >= 0 && y >= 0) {
				dp[ox][oy] = std::min(dp[ox][oy], dp[x][y]);
			}
			mn[mat[ox][oy] - 'a'] = std::min(dp[ox][oy], mn[mat[ox][oy] - 'a']);
		}
		int got = -1;
		for(int j = 0; j < 26; j++) {
			if(mn[j] <= k) {
				got = j;
				break;
			}
		}
		for(int j = 0; j < 26; j++) {
			if(mn[j] < k) {
				got = 0;
				break;
			}
		}
		assert(got >= 0);
		char c = (char) (got + 'a');
		for(auto pos : dist[d]) {
			int ox = pos.first, oy = pos.second;
			if(mat[ox][oy] != c) {
				dp[ox][oy]++;
			}
			if(dp[ox][oy] > k) {
				dp[ox][oy] = k + 2;
			}
		}
		ans += c;
	}
	std::cout << ans << std::endl;
}