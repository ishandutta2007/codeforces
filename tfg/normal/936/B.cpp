#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 1001000;

std::vector<int> edges[ms];

int vis[ms][2];
bool tie = false, win = false;

std::vector<int> path;

void dfs(int on, int par) {
	if(vis[on][par] == 1) {
		tie = true;
		return;
	} else if(vis[on][par]) {
		return;
	}
	path.push_back(on);
	vis[on][par] = 1;
	if(edges[on].size() == 0 && par == 1) {
		win = true;
		return;
	}
	for(auto to : edges[on]) {
		dfs(to, 1 - par);
		if(win) {
			return;
		}
	}
	vis[on][par] = 2;
	path.pop_back();
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		int size;
		scanf("%d", &size);
		while(size--) {
			int j;
			scanf("%d", &j);
			edges[i].push_back(j);
		}
	}
	int s;
	std::cin >> s;
	dfs(s, 0);
	if(win) {
		std::cout << "Win\n";
		for(int i = 0; i < path.size(); i++) {
			printf("%d%c", path[i], i + 1 == path.size() ? '\n' : ' ');
		}
	} else if(tie) {
		std::cout << "Draw\n";
	} else {
		std::cout << "Lose\n";
	}
}