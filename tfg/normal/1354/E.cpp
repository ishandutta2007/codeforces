#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

std::vector<int> edges[ms], partition[2], c;

void dfs(int on) {
	partition[c[on]].push_back(on);
	for(auto to : edges[on]) {
		if(c[to] != -1) {
			if(c[to] == c[on]) {
				std::cout << "NO\n";
				exit(0);
			}
		} else {
			c[to] = 1 ^ c[on];
			dfs(to);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	c.assign(n, -1);
	int sizes[3];
	std::cin >> sizes[0] >> sizes[1] >> sizes[2];
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::vector<std::pair<std::vector<int>, std::vector<int>>> wtf;
	for(int i = 0; i < n; i++) {
		if(c[i] == -1) {
			partition[0].clear();
			partition[1].clear();
			c[i] = 0;
			dfs(i);
			wtf.emplace_back(partition[0], partition[1]);
		}
	}
	int wot = (int) wtf.size();
	std::vector<std::bitset<ms>> dp(wot+1);
	dp[0][0] = 1;
	for(int i = 0; i < wot; i++) {
		dp[i+1] = (dp[i] << wtf[i].first.size()) | (dp[i] << wtf[i].second.size());
	}
	if(!dp[wot][sizes[1]]) {
		std::cout << "NO\n";
		return 0;
	}
	std::cout << "YES\n";
	partition[0].clear();
	partition[1].clear();
	for(int i = wot, j = sizes[1]; i > 0; i--) {
		if(j - (int) wtf[i-1].first.size() >= 0 && dp[i-1][j - (int) wtf[i-1].first.size()]) {
			assert(dp[i-1][j - (int) wtf[i-1].first.size()]);
			j -= (int) wtf[i-1].first.size();
			for(auto x : wtf[i-1].first) partition[0].push_back(x);
			for(auto x : wtf[i-1].second) partition[1].push_back(x);
		} else {
			wtf[i-1].first.swap(wtf[i-1].second);
			assert(dp[i-1][j - (int) wtf[i-1].first.size()]);
			j -= (int) wtf[i-1].first.size();
			for(auto x : wtf[i-1].first) partition[0].push_back(x);
			for(auto x : wtf[i-1].second) partition[1].push_back(x);
		}
	}
	assert((int) partition[0].size() == sizes[1]);
	assert((int) partition[1].size() + (int) partition[0].size() == n);
	for(int i = 0; i < (int) partition[0].size(); i++) {
		c[partition[0][i]] = 2;
	}
	for(int i = 0; i < (int) partition[1].size(); i++) {
		c[partition[1][i]] = i < sizes[0] ? 1 : 3;
	}
	for(int i = 0; i < n; i++) {
		std::cout << c[i];
	}
	std::cout << '\n';
}