#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;
const int MOD = 998244353;

std::vector< std::pair<int, int> > edges[ms];
int c[ms];

bool dfs(int on) {
	for(auto e : edges[on]) {
		if(c[e.first] == -1) {
			c[e.first] = c[on] ^ e.second;
			if(dfs(e.first)) {
				return true;
			}
		} else if(c[e.first] != (c[on] ^ e.second)) {
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = (int) str.size();
	std::reverse(str.begin(), str.end());
	int tot = 0;
	for(int size = 1; size < n; size++) {
		//std::cout << "solving for size " << size << std::endl;
		// edges for first
		for(int i = 0; i < n && n - i - 1 > i; i++) {
			edges[i].emplace_back(n - i - 1, 0);
			edges[n - i - 1].emplace_back(i, 0);
		}
		// edges for second
		for(int i = 0; i < size && size - i - 1 > i; i++) {
			edges[n + i].emplace_back(n + size - i - 1, 0);
			edges[n + size - i - 1].emplace_back(n + i, 0);
		}
		// edges between
		for(int i = 0; i < size; i++) {
			if(str[i] != '?') {
				edges[i].emplace_back(n + i, (str[i] - '0'));
				edges[n + i].emplace_back(i, (str[i] - '0'));
			}
		}
		// init for bicoloring
		for(int i = 0; i < n + size; i++) {
			c[i] = -1;
		}
		// dfs for known positions
		int ans = 1;
		for(int i = n-1; i >= size; i--) {
			if(str[i] != '?' && c[i] == -1) {
				c[i] = str[i] - '0';
				if(dfs(i)) {
					ans = 0;
				}
			}
			if(str[i] != '?' && c[i] != str[i] - '0') {
				ans = 0;
			}
		}
		if(c[n + size - 1] == -1) {
			c[n + size - 1] = 1;
			if(dfs(n + size - 1)) {
				ans = 0;
			}
		}
		if(c[n + size - 1] != 1) {
			ans = 0;
		}
		// dfs for unknown positions
		for(int i = 0; i < n + size; i++) {
			if(c[i] == -1) {
				c[i] = 0;
				if(dfs(i)) {
					ans = 0;
				} else {
					ans = (ans + ans) % MOD;
				}
			}
		}
		tot = (ans + tot) % MOD;
		// clearing graph
		for(int i = 0; i < size + n; i++) {
			edges[i].clear();
		}
	}
	std::cout << tot << '\n';
}