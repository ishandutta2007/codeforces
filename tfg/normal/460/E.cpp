#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

// [i][sumx][sumy] = max ans

const int ms = 2 * 31 * 8;
int dp[10][ms][ms];
std::pair<int, int> frm[10][ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, r;
	std::cin >> n >> r;
	const int INF = 1e9;
	for(int i = 0; i < 10; i++) for(int j = 0; j < ms; j++) for(int k = 0; k < ms; k++) dp[i][j][k] = -INF;
	std::vector<std::pair<int, int>> cands;
	for(int i = -r; i <= r; i++) {
		int j = 0;
		while(i * i + (j+1) * (j+1) <= r * r) j++;
		cands.emplace_back(i, j);
		if(j) cands.emplace_back(i, -j);
	}
	dp[0][ms/2][ms/2] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < ms; j++) for(int k = 0; k < ms; k++) {
			if(dp[i][j][k] == -INF) continue;
			int x = j - ms / 2, y = k - ms / 2;
			for(auto cand : cands) {
				int ans = dp[i][j][k] + (cand.first * cand.first + cand.second * cand.second) * (n-1) - 2 * (x * cand.first + y * cand.second);
				if(dp[i+1][j+cand.first][k+cand.second] < ans) {
					dp[i+1][j+cand.first][k+cand.second] = ans;
					frm[i+1][j+cand.first][k+cand.second] = cand;
				}
			}
		}
	}
	std::pair<int, int> st(0, 0);
	for(int i = 0; i < ms; i++) for(int j = 0; j < ms; j++) {
		if(dp[n][i][j] > dp[n][st.first][st.second]) {
			st = std::pair<int, int>(i, j);
		}
	}
	std::cout << dp[n][st.first][st.second] << '\n';
	for(int i = n; i > 0; i--) {
		auto vec = frm[i][st.first][st.second];
		std::cout << vec.first << ' ' << vec.second << '\n';
		st.first -= vec.first;
		st.second -= vec.second;
	}
}