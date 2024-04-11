#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 404;

int to[ms*ms][26];
int val[ms*ms];
int sz = 0;
std::vector<int> edges[ms*ms];

void init(int v) {
	memset(to[v], 0, sizeof to[v]);
	val[v] = 0;
	edges[v].clear();
}

void add(std::string str) {
	int on = 0;
	for(auto c : str) {
		int x = c - 'a';
		if(to[on][x] == 0) {
			init(sz);
			to[on][x] = sz++;
			edges[on].push_back(x);
		}
		on = to[on][x];
	}
	val[on] = (int) str.size();
}

int table[ms][26];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--) {
		std::string s, t;
		std::cin >> s >> t;
		int n = (int) s.size();
		for(int i = 0; i < 26; i++) {
			table[n][i] = n;
		}
		for(int i = n-1; i >= 0; i--) {
			for(int j = 0; j < 26; j++) {
				table[i][j] = table[i+1][j];
			}
			table[i][s[i] - 'a'] = i;
		}
		int m = (int) t.size();
		sz = 0;
		init(sz++);
		for(int i = 0; i < m; i++) {
			add(t.substr(i, m-i));
		}
		std::vector<std::vector<int>> dp(m+1, std::vector<int>(sz, n+1));
		dp[0][0] = 0;
		bool good = false;
		for(int i = 0; i <= m && !good; i++) {
			for(int j = 0; j < sz && !good; j++) {
				if(dp[i][j] <= n && i + val[j] == m) {
					good = true;
					break;
				}
				if(dp[i][j] >= n) continue;
				if(i < m) {
					dp[i+1][j] = std::min(dp[i+1][j], 1 + table[dp[i][j]][t[i]-'a']);
				}
				for(auto k : edges[j]) {
					dp[i][to[j][k]] = std::min(dp[i][to[j][k]], 1 + table[dp[i][j]][k]);
				}
			}
		}
		std::cout << (good ? "YES\n" : "NO\n");
	}
}