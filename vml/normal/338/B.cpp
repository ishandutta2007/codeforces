#define _CRT_SECURE_NO_WARNINGS

#pragma comment (linker, "/STACK:16777216")

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 100000 + 10;
const int MAX_M = 100000 + 10;
const int inf = 1 << 30;

bool good[MAX_N];
int dist_down[MAX_N];
int dist_up[MAX_N];
vector <int> g[MAX_N];

int dfs_down(int v, int last) {
	if (good[v]) {
		dist_down[v] = 0;
	} else {
		dist_down[v] = -inf;
	}
	for (int i = 0; i < (int)g[v].size(); i++) {
		int u = g[v][i];
		if (u != last) {
			int d = dfs_down(u, v);
			if (d != -inf) {
				dist_down[v] = max(dist_down[v], d + 1);
			}
		}
	}
	return dist_down[v];
}

void dfs_up(int v, int last) {
	int max_first = -inf, max_second = -inf;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int u = g[v][i];
		if (u != last) {
			if (dist_down[u] > max_first) {
				max_second = max_first;
				max_first = dist_down[u];
			} else if (dist_down[u] > max_second) {
				max_second = dist_down[u];
			}
		}
	}
	for (int i = 0; i < (int)g[v].size(); i++) {
		int u = g[v][i];
		if (u != last) {
			int d;
			if (dist_down[u] == max_first) {
				d = max_second;
 			} else {
				d = max_first;
			}
			dist_up[u] = d;
			if (d != -inf) {
				dist_up[u] += 2;
			}

			if (dist_up[v] != -inf) {
				dist_up[u] = max(dist_up[u], dist_up[v] + 1);
			}

			if (good[u]) {
				dist_up[u] = max(dist_up[u], 0);
			}
			dfs_up(u, v);
		}
	}
}

int main() {
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i++) {
		int v;
		scanf("%d", &v);
		good[v] = true;
	}
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs_down(1, -1);
	if (good[1]) {
		dist_up[1] = 0;
	} else {
		dist_up[1] = -inf;
	}
	dfs_up(1, -1);
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (max(dist_down[i], dist_up[i]) <= d) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}