#include <iostream>
#include <vector>

const int ms = 100100;

int val[ms];
std::vector<int> edges[ms];

int dfs(int on, int par, int con, int lim) {
	if(val[on]) {
		con++;
	} else {
		con = 0;
	}
	if(con > lim) {
		return 0;
	}
	if(par != 0 && edges[on].size() == 1) {
		return 1;
	}
	int ans = 0;
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		ans += dfs(to, on, con, lim);
	}
	return ans;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		std::cin >> val[i];
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::cout << dfs(1, 0, 0, m) << '\n';
}