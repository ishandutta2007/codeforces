#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, LOG = 21;

long long INF = 1ll << 60;

int n, m, k, q;

long long dis[N][LOG];

int dep[N], fa[N][LOG];

bool vis[N];

vector<pair<int, int> > e[N];

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	for (int i = 0; i < n; ++i) {
		dis[i][0] = INF;
		fa[i][0] = -1;
	}
	int root = 0;
	dis[root][0] = 0;
	fa[root][0] = 0;
	dep[root] = 0;
	priority_queue<pair<long long, int> > heap;
	heap.push(make_pair(-dis[root][0], root));
	while (heap.size()) {
		long long d = -heap.top().first;
		int u = heap.top().second;
		heap.pop();
		if (dis[u][0] != d) {
			continue;
		}
		if (u < k) {
			vis[u] = true;
		}
		//cout << u << ' ' << dis[u][0] << ' ' << fa[u][0] << endl;
		for (int i = 0; i < (int)e[u].size(); ++i) {
			int v = e[u][i].first, w = e[u][i].second;
			if (v < k && vis[v]) {
				continue;
			}
			long long nd;
			int nf;
			if (u < k) {
				nd = w, nf = u;
			} else {
				nd = d + w, nf = fa[u][0];
			}
			if (nd < dis[v][0]) {
				dis[v][0] = nd;
				fa[v][0] = nf;
				dep[v] = dep[nf] + 1;
				heap.push(make_pair(-dis[v][0], v));
			}
		}
	}
	for (int j = 1; j < LOG; ++j) {
		for (int i = 0; i < k; ++i) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
			dis[i][j] = max(dis[i][j - 1], dis[fa[i][j - 1]][j - 1]);
		}
	}
	while (q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		long long ans = 0;
		if (dep[u] < dep[v]) {
			swap(u, v);
		}
		for (int i = LOG - 1; i >= 0; --i) {
			if (dep[u] - (1 << i) >= dep[v]) {
				ans = max(ans, dis[u][i]);
				u = fa[u][i];
			}
		}
		if (u != v) {
			for (int i = LOG - 1; i >= 0; --i) {
				if (fa[u][i] != fa[v][i]) {
					ans = max(ans, dis[u][i]);
					u = fa[u][i];
					ans = max(ans, dis[v][i]);
					v = fa[v][i];
				}
			}
			ans = max(ans, dis[u][0]);
			u = fa[u][0];
			ans = max(ans, dis[v][0]);
			v = fa[v][0];
		}
		printf("%I64d\n", ans);
	}
	return 0;
}