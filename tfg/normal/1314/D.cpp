#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, k;
int dist[80][80];
std::pair<int, int> ord[80][80][6];
bool got[80];
std::vector<int> cur;
int trans[5][5];
int dp[5];
int nxt[5];

int ans = 1e9 + 10;

void solve(int on) {
	if((int) cur.size() == k || on == n) {
		if((int) cur.size() == n) return;
		// get transition
		for(int i = 0; i < (int) cur.size(); i++) {
			for(int j = 0; j < (int) cur.size(); j++) {
				int x = 0;
				while(got[ord[cur[i]][cur[j]][x].second]) x++;
				//assert(x < 6 && ord[cur[i]][cur[j]][x].second != -1);
				trans[i][j] = ord[cur[i]][cur[j]][x].first;
			}
		}
		// do dp
		for(int i = 0; i < (int) cur.size(); i++) {
			dp[i] = 1e9 + 10;
		}
		dp[0] = 0;
		for(int x = 0; x < k; x++) {
			for(int i = 0; i < (int) cur.size(); i++) {
				nxt[i] = 1e9 + 10;
			}
			for(int i = 0; i < (int) cur.size(); i++) {
				for(int j = 0; j < (int) cur.size(); j++) {
					nxt[j] = std::min(nxt[j], dp[i] + trans[i][j]);
				}
			}
			for(int i = 0; i < (int) cur.size(); i++) {
				dp[i] = nxt[i];
			}
		}
		ans = std::min(ans, dp[0]);
		//std::cout << "got " << dp[0] << std::endl;
	} else {
		cur.push_back(on);
		got[on] = true;
		solve(on+1);
		got[on] = false;
		cur.pop_back();
		solve(on+1);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> k;
	k = k / 2;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cin >> dist[i][j];
			if(i == j) {
				dist[i][j] = 1e9 + 10;
			}
			for(int x = 0; x < 6; x++) {
				ord[i][j][x] = std::pair<int, int>(1e9 + 10, -1);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			for(int x = 0; x < n; x++) {
				ord[i][j][5] = std::pair<int, int>(dist[i][x] + dist[x][j], x);
				std::sort(ord[i][j], ord[i][j] + 6);
			}
		}
	}
	cur.push_back(0);
	got[0] = true;
	solve(1);
	std::cout << ans << '\n';
}