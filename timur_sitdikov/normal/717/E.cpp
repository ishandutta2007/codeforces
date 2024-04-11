#include <bits/stdc++.h>
using namespace std;

#ifdef HELTHAZAR
#define DEBUG true
#else
#define DEBUG false
#endif

#define dout if (DEBUG) cout

const int MAXN = 200001;

int color[MAXN];
vector<int> edges[MAXN];

int hascolor[MAXN];

void dfs_dp(int v, int p = -1) {
	hascolor[v] = color[v];
	for (int i = 0; i < edges[v].size(); i++) {
		int next = edges[v][i];
		if (next == p) {
			continue;
		}
		dfs_dp(next, v);
		hascolor[v] |= hascolor[next];
	}
}

vector<int> path;

void dfs_color(int v, int p = -1) {
	color[v] = !color[v];
	path.push_back(v);
	for (int i = 0; i < edges[v].size(); i++) {
		int next = edges[v][i];
		if (next == p) {
			continue;
		}
		if (hascolor[next]) {
			dfs_color(next, v);
			color[v] = !color[v];
			path.push_back(v);
		}
		if (hascolor[next]) {
			dfs_color(next, v);
			color[v] = !color[v];
			path.push_back(v);
		}
	}
	hascolor[v] = color[v];
}

void solve(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> color[i];
		if (color[i] == 1) {
			color[i] = 0;
		}
		else {
			color[i] = 1;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	color[1] = !color[1];

	dfs_dp(1);
	dfs_color(1);

	if (color[1]) {
		color[1] = !color[1];
		path.pop_back();
	}

	if (path.empty()) {
		int next = edges[1][0];
		path.push_back(1);
		path.push_back(next);
		path.push_back(1);
		path.push_back(next);
	}

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
}

int main(){
	int t = 1;
	while (t--) {
		solve();
		cout << endl;
	}
}