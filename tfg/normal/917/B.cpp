#include <iostream>
#include <vector>
#include <cstring>

typedef std::pair<int, int> ic;

const int ms = 101;

std::vector<ic> edges[ms];

bool visit[ms][ms];
int memo[ms][ms];

int dp(int u, int v) {
	int &ans = memo[u][v];
	if(visit[u][v]) {
		return ans;
	}
	ans = -1;
	visit[u][v] = true;
	for(auto e : edges[u]) {
		if(dp(v, e.first) < e.second)
			ans = std::max(ans, e.second);
	}
	return ans;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	while(m--) {
		int u, v;
		char c;
		std::cin >> u >> v >> c;
		edges[u - 1].push_back(ic(v - 1, c - 'a'));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << (dp(i, j) < 0 ? 'B' : 'A');
		}
		std::cout << '\n';
	}
}