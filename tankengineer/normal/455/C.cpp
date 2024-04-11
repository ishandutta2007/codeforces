#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 3 * 100005;

int n, m, q;

int fa[N];

int find(int u) {
	return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
	fa[u] = v;
}

vector<int> edge[N];

int dis[N];
bool vis[N];

int ans[N];

void calDia(int st) {
	vector<int> q;
	q.push_back(st);
	dis[st] = 0;
	vis[st] = true;
	for (int i = 0; i < (int)q.size(); ++i) {
		int u = q[i];
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (vis[v]) {
				continue;
			}
			vis[v] = true;
			dis[v] = dis[u] + 1;
			q.push_back(v);
		}
	}
	int st2 = st;
	for (int i = 0; i < (int)q.size(); ++i) {
		if (dis[q[i]] > dis[st2]) {
			st2 = q[i];
		}
		vis[q[i]] = false;
	}
	q.clear();
	q.push_back(st2);
	dis[st2] = 0;
	vis[st2] = true;
	for (int i = 0; i < (int)q.size(); ++i) {
		int u = q[i];
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (vis[v]) {
				continue;
			}
			vis[v] = true;
			dis[v] = dis[u] + 1;
			q.push_back(v);
		}
	}
	int st3 = st2;
	for (int i = 0; i < (int)q.size(); ++i) {
		if (dis[q[i]] > dis[st3]) {
			st3 = q[i];
		}
	}
	ans[find(st)] = dis[st3] + 1;
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		merge(find(u), find(v));
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			calDia(i);
		}
	}
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int u;
			scanf("%d", &u);
			--u;
			printf("%d\n", ans[find(u)] - 1);
		} else {
			int u, v;
			scanf("%d%d", &u, &v);
			--u, --v;
			u = find(u);
			v = find(v);
			if (u == v) {
				continue;
			}
			merge(u, v);
			ans[v] = max(max(ans[v], ans[u]), ans[v] / 2 + 1 + ans[u] / 2 + 1);
		}
	}
	return 0;
}