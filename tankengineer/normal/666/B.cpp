#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 1000000005, N = 3005;

int n, m;

vector<int> edge[N];

int g[N][N];

int from[N][3], to[N][3];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			g[i][j] = INF;
		}
		g[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
	}
	for (int i = 0; i < n; ++i) {
		queue<int> q;
		q.push(i);
		while (q.size()) {
			int u = q.front();
			q.pop();
			for (int j = 0; j < (int)edge[u].size(); ++j) {
				int v = edge[u][j];
				if (g[i][v] > g[i][u] + 1) {
					g[i][v] = g[i][u] + 1;
					q.push(v);
				}
			}
		}
	}
	memset(from, -1, sizeof(from));
	memset(to, -1, sizeof(to));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j || g[j][i] == INF) {
				continue;
			}
			int cur = j;
			for (int k = 0; k < 3; ++k) {
				if (from[i][k] == -1 || g[from[i][k]][i] < g[cur][i]) {
					swap(cur, from[i][k]);
				}
			}
		}
		for (int j = 0; j < n; ++j) {
			if (i == j || g[i][j] == INF) {
				continue;
			}
			int cur = j;
			for (int k = 0; k < 3; ++k) {
				if (to[i][k] == -1 || g[i][to[i][k]] < g[i][cur]) {
					swap(cur, to[i][k]);
				}
			}
		}
	}
	int ans = 0;
	vector<int> anst;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j || g[i][j] == INF) {
				continue;
			}
			for (int ii = 0; ii < 3; ++ii) {
				int u = from[i][ii];
				if (u == -1 || u == j) {
					continue;
				}
				for (int jj = 0; jj < 3; ++jj) {
					int v = to[j][jj];
					if (v == -1 || v == i || v == u) {
						continue;
					}
					int d = g[u][i] + g[i][j] + g[j][v];
					if (d > ans) {
						ans = d;
						anst.clear();
						anst.push_back(u);
						anst.push_back(i);
						anst.push_back(j);
						anst.push_back(v);
					}
				}
			}
		}
	}
	//printf("%d\n", ans);
	for (int i = 0; i < 4; ++i) {
		printf("%d%c", anst[i] + 1, i == 3 ? '\n' : ' ');
	}
	return 0;
}