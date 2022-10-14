#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, q, x[500005], y[500005], w[500005];
int prv[500005][25], rt[500005], dep[500005];
int dfn[500005], dfo[500005], cur;
bool spec[500005];
vector<PII> G[500005];

int up(int x, int d)
{
	for(int i = 24; i >= 0; i --) if(d >> i & 1) x = prv[x][i];
	return x;
}

int lca(int x, int y)
{
	if(dep[x] > dep[y]) swap(x, y);
	y = up(y, dep[y] - dep[x]);
	for(int i = 24; i >= 0; i --) if(prv[x][i] != prv[y][i]) x = prv[x][i], y = prv[y][i];
	return x == y ? x : prv[x][0];
}

int root(int x)
{
	return rt[x] == x ? x : rt[x] = root(rt[x]);
}

int ksorko[500005];
bool vis[500005];
void dfs(int v, int par)
{
	vis[v] = true;
	dep[v] = dep[par] + 1;
	dfn[v] = ++ cur;
	prv[v][0] = par;
	rep1(i, 24) prv[v][i] = prv[prv[v][i - 1]][i - 1];
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		int x = G[v][i].second;
		if(u == par) continue;
		ksorko[u] = ksorko[v] ^ x;
		dfs(u, v);
	}
	dfo[v] = cur;
}

struct fenw
{
	int dat[300005];
	void add(int id, int val) {
		for(id ++; id < 300005; id += id & -id) dat[id] += val;
	}
	int query(int id) {
		if(id == 0) return 0;
		int ret = 0;
		for(id ++; id > 0; id -= id & -id) ret += dat[id];
		return ret;
	}
} T1;

int main()
{
	scanf("%d%d", &n, &q);
	rep1(i, n) rt[i] = i;
	rep1(i, q) {
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		if(root(x[i]) != root(y[i])) {
			G[x[i]].push_back(MP(y[i], w[i]));
			G[y[i]].push_back(MP(x[i], w[i]));
			rt[root(x[i])] = root(y[i]);
			spec[i] = true;
		}
	}
	rep1(i, n) if(!vis[i]) dfs(i, i);
	rep1(i, q) {
		if(spec[i]) {
			printf("YES\n");
			continue;
		}
		if(dep[x[i]] > dep[y[i]]) swap(x[i], y[i]);
		int cc = T1.query(dfn[x[i]]) + T1.query(dfn[y[i]]) - 2 * T1.query(dfn[lca(x[i], y[i])]);
		int xr = ksorko[x[i]] ^ ksorko[y[i]];
		if(cc == 0 && xr != w[i]) {
			printf("YES\n");
			int l = lca(x[i], y[i]);
			while(x[i] != l) {
				T1.add(dfn[x[i]], 1);
				T1.add(dfo[x[i]] + 1, -1);
				x[i] = prv[x[i]][0];
			}
			while(y[i] != l) {
				T1.add(dfn[y[i]], 1);
				T1.add(dfo[y[i]] + 1, -1);
				y[i] = prv[y[i]][0];
			}
		} else {
			printf("NO\n");
		}
	}
	return 0;
}