#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100100;
int ed[N][2];
int n, m;
vector<int> g[N];
ll c[N];
int col[N];
int par[N];
ll ans[N];
vector<int> cycle;

int getOther(int id, int v) {
	return v ^ ed[id][0] ^ ed[id][1];
}

int dfs1(int v) {
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (col[u] != -1) {
			if (col[v] == col[u]) {
				cycle.push_back(id);
				int w = v;
				while(w != u) {
					cycle.push_back(par[w]);
					w = getOther(par[w], w);
				}
				return u;
			}
			continue;
		}
		col[u] = col[v] ^ 1;
		par[u] = id;
		int w = dfs1(u);
		if (w != -1)
			return w;
	}
	return -1;
}

void dfs2(int v) {
	for (int id : g[v]) {
		int u = getOther(id, v);
		if (par[u] != -1) continue;
		par[u] = id;
		dfs2(u);
		ans[id] += c[u];
		c[v] -= c[u];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &c[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ed[i][0], &ed[i][1]);
		ed[i][0]--;
		ed[i][1]--;
		g[ed[i][0]].push_back(i);
		g[ed[i][1]].push_back(i);
	}
	for (int i = 0; i < n; i++)
		col[i] = -1;
	col[0] = 0;
	int V = dfs1(0);
	for (int i = 0; i < n; i++)
		par[i] = -1;
	if (V == -1) {
		par[0] = -2;
		dfs2(0);
	} else {
		par[V] = -2;
		dfs2(V);
	}
	if (V == -1 && c[0] != 0) {
		printf("NO\n");
		return 0;
	}
	if (V == -1) V = 0;
	for (int i = 0; i < (int)cycle.size(); i++) {
		if (i & 1)
			ans[cycle[i]] -= c[V] / 2;
		else
			ans[cycle[i]] += c[V] / 2;
	}
	printf("YES\n");
	for (int i = 0; i < m; i++)
		printf("%lld\n", ans[i]);

	return 0;
}