#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const long long INF = 1e12; 

int n, m;

std::vector<int> safe[ms];
bool got[ms];
int left[ms], right[ms];
long long memo[ms][10];

long long dp(int on, int col) {
	int id = std::lower_bound(safe[on].begin(), safe[on].end(), col) - safe[on].begin();
	if(id >= (int) safe[on].size() || safe[on][id] != col) {
		return INF;
	}
	long long &ans = memo[on][id];
	if(ans != -1) return ans;
	if(on+1 == n) {
		return ans = std::min(right[on] - left[on] + abs(col - left[on]), right[on] - left[on] + abs(col - right[on]));
	}
	ans = INF;
	int cost, to;
	if(!got[on]) {
		return ans = dp(on+1, col);
	}
	{
		to = left[on];
		cost = abs(right[on] - col) + right[on] - left[on];
		for(int i = 0; i < (int) safe[on].size(); i++) {
			ans = std::min(ans, cost + dp(on+1, safe[on][i]) + abs(to - safe[on][i]));
		}
	}
	{
		to = right[on];
		cost = abs(left[on] - col) + right[on] - left[on];
		for(int i = 0; i < (int) safe[on].size(); i++) {
			ans = std::min(ans, cost + dp(on+1, safe[on][i]) + abs(to - safe[on][i]));
		}
	}
	//std::cout << "at (" << on << ", " << col << ") returning " << ans << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int k, q;
	std::cin >> n >> m >> k >> q;
	while(k--) {
		int r, c;
		std::cin >> r >> c;
		r--;c--;
		if(!got[r]) {
			got[r] = true;
			left[r] = right[r] = c;
		} else {
			left[r] = std::min(left[r], c);
			right[r] = std::max(right[r], c);
		}
	}
	std::vector<int> wtf(q);
	for(auto &v : wtf) {
		std::cin >> v;
		v--;
	}
	std::sort(wtf.begin(), wtf.end());
	while(!got[n-1]) n--;
	//std::cout << "n is " << n << '\n';
	for(int i = 0; i < n; i++) {
		if(got[i]) {
			{
				int id = std::lower_bound(wtf.begin(), wtf.end(), left[i]) - wtf.begin();
				if(id < q) {
					safe[i].push_back(wtf[id]);
				}
				id--;
				if(id >= 0) {
					safe[i].push_back(wtf[id]);
				}
			}
			{
				int id = std::lower_bound(wtf.begin(), wtf.end(), right[i]) - wtf.begin();
				if(id < q) {
					safe[i].push_back(wtf[id]);
				}
				id--;
				if(id >= 0) {
					safe[i].push_back(wtf[id]);
				}
			}
		} else {
			if(i > 0) {
				safe[i] = safe[i-1];
			} else {
				safe[i].push_back(wtf[0]);
			}
		}
	}
	for(int i = n-1; i >= 0; i--) {
		if(i > 0) {
			for(auto v : safe[i-1]) {
				safe[i].push_back(v);
			}
		}
		std::sort(safe[i].begin(), safe[i].end());
		safe[i].resize(std::unique(safe[i].begin(), safe[i].end()) - safe[i].begin());
		assert((int) safe[i].size() <= 9);
	}
	for(int i = 0; i < n; i++) {
		break;
		if(!got[i]) {
			std::cout << i << " doesn't have treasures\n";
		} else {
			std::cout << i << ": (" << left[i] << ", " << right[i] << ")\n";
		}
	}
	memset(memo, -1, sizeof memo);
	if(n == 1) {
		safe[0].push_back(0);
		std::sort(safe[0].begin(), safe[0].end());
		safe[0].resize(std::unique(safe[0].begin(), safe[0].end()) - safe[0].begin());
		std::cout << dp(0, 0) << '\n';
	} else {
		if(!got[0]) {
			std::cout << dp(0, wtf[0]) + n-1 + wtf[0] << '\n';
		} else {
			long long ans = INF;
			int on = 0;
			int col = 0;
			{
				int to = left[on];
				int cost = abs(right[on] - col) + right[on] - left[on];
				//std::cout << "cost1 is " << cost << '\n';
				for(int i = 0; i < (int) safe[on].size(); i++) {
					ans = std::min(ans, cost + dp(on+1, safe[on][i]) + abs(to - safe[on][i]));
					//std::cout << cost << " + " << dp(on+1, safe[on][i]) << " + " << abs(to - safe[on][i]) << '\n';
				}
			}
			{
				int to = right[on];
				int cost = abs(left[on] - col) + right[on] - left[on];
				//std::cout << "cost2 is " << cost << '\n';
				for(int i = 0; i < (int) safe[on].size(); i++) {
					ans = std::min(ans, cost + dp(on+1, safe[on][i]) + abs(to - safe[on][i]));
					//std::cout << cost << " + " << dp(on+1, safe[on][i]) << " + " << abs(to - safe[on][i]) << '\n';
				}
			}
			std::cout << ans + n - 1 << '\n';
		}
	}
}