#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Block {
	int a[10], n;

	Block() {
		n = 0;
	}

	void add(int num) {
		int pos = lower_bound(a, a + n, num) - a;
		if (pos < 10) {
			for (int i = n - 1; i > pos; --i) {
				a[i] = a[i - 1];
			}
			a[pos] = num;
			n = min(n + 1, 10);
		}
	}
};

Block operator + (const Block &a, const Block &b) {
	Block ret;
	int i = 0, j = 0;
	while (i < a.n && j < b.n && ret.n < 10) {
		if (a.a[i] < b.a[j]) {
			ret.a[ret.n++] = a.a[i++];
		} else {
			ret.a[ret.n++] = b.a[j++];
		}
	}
	while (i < a.n && ret.n < 10) {
		ret.a[ret.n++] = a.a[i++];
	}
	while (j < b.n && ret.n < 10) {
		ret.a[ret.n++] = b.a[j++];
	}
	return ret;
}

const int N = 100005;

int n, m, q;

int fa[N];

Block ans[N], p[N];

int find(int u) {
	if (u == fa[u]) {
		return u;
	} else {
		int v = fa[u];
		fa[u] = find(v);
		if (fa[v] != v) {
			p[u] = p[u] + p[v];
		}
		return fa[u];
	}
}

void merge(int u, int v) {
	fa[u] = v;
}

vector<int> edge[N];

vector<pair<int, int> > que[N];

vector<pair<pair<int, int>, int> > lca[N];

int k[N];

bool vis[N];

void tarjan(int u, int father = -1) {
	vis[u] = true;
	for (int i = 0; i < (int)edge[u].size(); ++i) {
		int v = edge[u][i];
		if (vis[v]) {
			continue;
		}
		tarjan(v, u);
	}
	for (int i = 0; i < (int)que[u].size(); ++i) {
		int v = que[u][i].first, id = que[u][i].second;
		if (!vis[v]) {
			continue;
		}
		lca[find(v)].push_back(make_pair(make_pair(u, v), id));
	}
	int w = u;
	for (int i = 0; i < (int)lca[w].size(); ++i) {
		int u = lca[w][i].first.first, v = lca[w][i].first.second, id = lca[w][i].second;
		find(u), find(v);
		if (u != v) {
			ans[id] = p[u] + p[v];
		} else {
			ans[id] = p[u];
		}
		if (u != w && v != w) {
			ans[id] = ans[id] + p[w];
		}
	}
	if (~father) {
		merge(u, father);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 0; i < m; ++i) {
		int u;
		scanf("%d", &u);
		--u;
		p[u].add(i + 1);
	}
	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d%d%d", &u, &v, k + i);
		--u, --v;
		que[u].push_back(make_pair(v, i));
		if (u != v) {
			que[v].push_back(make_pair(u, i));
		}
	}
	tarjan(0);
	for (int i = 0; i < q; ++i) {
		int t = min(k[i], ans[i].n);
		printf("%d", t);
		for (int j = 0; j < t; ++j) {
			printf(" %d", ans[i].a[j]);
		}
		printf("\n");
	}
	return 0;
}