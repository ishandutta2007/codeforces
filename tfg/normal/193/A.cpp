#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;

std::vector<int> edges[ms];
int id[55][55], c = 0;
int low[ms], dp[ms];

void dfs(int on, int par, int h = 1) {
	low[on] = h;
	dp[on] = h;
	int child = 0;
	bool isArticulation = false;
	for(auto to : edges[on]) {
		if(to == par) continue;
		if(low[to] != 0) {
			low[on] = std::min(low[on], dp[to]);
		} else {
			child++;
			dfs(to, on, h + 1);
			low[on] = std::min(low[on], low[to]);
			if(low[to] >= h) {
				isArticulation = true;
			}
		}
	}
	if(on == par) {
		if(child > 1) {
			std::cout << "1\n";
			exit(0);
		}
	} else if(isArticulation) {
		std::cout << "1\n";
		exit(0);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char hmm;
			std::cin >> hmm;
			if(hmm == '.') {
				id[i][j] = -1;
			} else {
				id[i][j] = c++;
			}
		}
	}
	if(c <= 2) {
		std::cout << "-1\n";
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(id[i][j] != -1) {
					if(i && id[i-1][j] != -1) {
						int u = id[i][j], v = id[i-1][j];
						edges[u].push_back(v);
						edges[v].push_back(u);
					}
					if(j && id[i][j-1] != -1) {
						int u = id[i][j], v = id[i][j-1];
						edges[u].push_back(v);
						edges[v].push_back(u);
					}
				}
			}
		}
		dfs(0, 0);
		std::cout << "2\n";
	}
}