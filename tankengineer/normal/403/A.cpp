#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 25;

int n, p;
bool g[N][N];
vector<pair<int, int> > edge;

void addedge(int u, int v) {
	g[u][v] = g[v][u] = true;
	edge.push_back(make_pair(u + 1, v + 1));
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &p);
		edge.clear();
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; ++i) {
			addedge(i, (i + 1) % n);
			addedge(i, (i + 2) % n);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (!g[i][j] && p > 0) {
					--p;
					addedge(i, j);
				}
			}
		}
		for (int i = 0; i < (int)edge.size(); ++i) {
			printf("%d %d\n", edge[i].first, edge[i].second);
		}
	}
	return 0;
}