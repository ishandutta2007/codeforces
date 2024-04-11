#include <iostream>
#include <vector>
#include <cstdio>

const int ms = 100100;

std::vector<int> edges[ms];
int size[ms];

int dfs(int on, int par = -1) {
	int ans = 0;
	for(auto to : edges[on]) {
		if(to != par) {
			ans += dfs(to, on);
			size[on] += size[to];
		}
	}
	size[on]++;
	if(par != -1 && size[on] % 2 == 0) {
		ans++;
	}
	return ans;
}

int main() {
	int n;
	std::cin >> n;
	if(n % 2 == 1) {
		std::cout << "-1\n";
		return 0;
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::cout << dfs(1) << std::endl;
}