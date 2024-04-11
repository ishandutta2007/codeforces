#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 100100;

std::vector<int> edges[ms];

int dfs(int on, int par) {
	for(auto to : edges[on]) {
		if(to != par) {
			return dfs(to, on);
		}
	}
	return on;
}

int main() {
	int n;
	std::cin >> n;
	if(n == 2) {
		std::cout << "Yes\n1\n1 2\n";
		return 0;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int leaves = 0;
	for(int i = 0; i < n; i++) {
		if(edges[i].size() == 1) {
			leaves++;
		}
	}
	for(int i = 0; i < n; i++) {
		if(edges[i].size() == leaves) {
			std::cout << "Yes\n" << leaves << "\n";
			for(auto to : edges[i]) {
				printf("%d %d\n", i + 1, dfs(to, i) + 1);
			}
			return 0;
		}
	}
	std::cout << "No\n";
}