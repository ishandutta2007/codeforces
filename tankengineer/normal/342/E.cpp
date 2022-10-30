#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define div DIV

const int N = 1000005;
int n, dis[N], fa[N], mc[N], size[N];
bool div[N];
vector<int> edge[N];
vector<pair<int, int> > pa[N];

void divide(int r) {
	queue<int> q;
	q.push(r);
	fa[r] = -1;
	vector<int> v;
	while (q.size()) {
		int u = q.front();
		q.pop();
		size[u] = 0;
		mc[u] = 0;
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (div[v] || v == fa[u]) {
				continue;
			}
			fa[v] = u;
			q.push(v);
		}
		v.push_back(u);
	}
	int n = v.size();
	int cen = -1;
	for (int i = n - 1; i >= 0; --i) {
		int u = v[i];
		++size[u];
		if (~fa[u]) {
			size[fa[u]] += size[u];
			mc[fa[u]] = max(mc[fa[u]], size[u]);
		}
		mc[u] = max(mc[u], n - size[u]);
		if (cen == -1 || mc[u] < mc[cen]) {
			cen = u;
		}
	}
	q.push(cen);
	dis[cen] = 0;
	fa[cen] = -1;
	pa[cen].push_back(make_pair(cen, 0));
	while (q.size()) {
		int u = q.front();
		q.pop();
		for (int j = 0; j < (int)edge[u].size(); ++j) {
			int v = edge[u][j];
			if (div[v] || v == fa[u]) {
				continue;
			}
			fa[v] = u;
			dis[v] = dis[u] + 1;
			q.push(v);
			pa[v].push_back(make_pair(cen, dis[v]));
		}
	}
	div[cen] = true;
	for (int j = 0; j < (int)edge[cen].size(); ++j) {
		int v = edge[cen][j];
		if (div[v]) {
			continue;
		}
		divide(v);
	}
}

const int INF = 200000000;
int ans[N];

void mark(int u) {
	for (int i = 0; i < (int)pa[u].size(); ++i) {
		int f = pa[u][i].first, d = pa[u][i].second;
		ans[f] = min(ans[f], d);
	}
}

int ask(int u) {
	int ret = INF;
	for (int i = 0; i < (int)pa[u].size(); ++i) {
		int f = pa[u][i].first, d = pa[u][i].second;
		ret = min(ret, ans[f] + d);
	}
	return ret;
}

int main() {
	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n - 1; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t1, --t2;
		edge[t1].push_back(t2);
		edge[t2].push_back(t1);
	}
	divide(0);
	for (int i = 0; i < n; ++i) {
		ans[i] = INF;
	}
	mark(0);
	for (int i = 0; i < q; ++i) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		--t2;
		if (t1 == 1) {
			mark(t2);
		} else {
			printf("%d\n", ask(t2));
		}
	}
	return 0;
}