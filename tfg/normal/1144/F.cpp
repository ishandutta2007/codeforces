#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int ed[ms][2];
std::vector<int> edges[ms];
int c[ms];

void dfs(int on) {
	for(auto to : edges[on]) {
		if(c[to] != -1) {
			if(c[to] == c[on]) {
				std::cout << "NO\n";
				exit(0);
			}
		} else {
			c[to] = c[on] ^ 1;
			dfs(to);
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		ed[i][0] = u;
		ed[i][1] = v;
	}
	memset(c, -1, sizeof c);
	for(int i = 0; i < n; i++) {
		if(c[i] == -1) {
			c[i] = 0;
			dfs(i);
		}
	}
	std::cout << "YES\n";
	for(int i = 0; i < m; i++) {
		std::cout << c[ed[i][0]];
	}
	std::cout << '\n';
}