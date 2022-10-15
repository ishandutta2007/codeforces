#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>

const int N = 2e5 + 7;

int n;
std::vector<int> path;
std::vector<int> adj[N];
int color[N];

void move(int x) {
	color[x] *= -1;
	path.push_back(x);
}

void dfs(int x, int fa) {
	move(x);
	for (int y : adj[x]) {
		if (y != fa) {
			dfs(y, x);
			move(x);
		}
	}
	if (fa && color[x] != 1) {
		move(fa);
		move(x);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	color[1] = -color[1];
	dfs(1, 0);
	if (color[1] != 1) {
		path.pop_back();
	}
	for (int i = 0; i < path.size(); i++) {
		printf("%d%c", path[i], i + 1 == path.size() ? '\n' : ' ');
	}
	return 0;
}