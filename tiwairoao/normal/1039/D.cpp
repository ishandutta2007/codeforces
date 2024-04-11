#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int SQRT = 1100;

vector<int>G[MAXN + 5];
void addedge(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}

int dfn[MAXN + 5], fa[MAXN + 5], dcnt;
void dfs(int x, int f) {
	dfn[++dcnt] = x, fa[x] = f;
	for(int i=0;i<G[x].size();i++)
		if( G[x][i] != f ) dfs(G[x][i], x);
}

int mx[MAXN + 5], smx[MAXN + 5], f[MAXN + 5], g[MAXN + 5], n;

int solve(int x) {
	for(register int i=1;i<=n;i++) mx[i] = smx[i] = f[i] = 0;
	for(register int i=n;i>=1;i--) {
		int k = dfn[i];
		if( mx[k] + smx[k] + 1 >= x )
			f[k]++, g[k] = 0;
		else g[k] = mx[k] + 1;
		
		if( fa[k] ) {
			f[fa[k]] += f[k];
			if( g[k] > mx[fa[k]] )
				smx[fa[k]] = mx[fa[k]], mx[fa[k]] = g[k];
			else if( g[k] > smx[fa[k]] )
				smx[fa[k]] = g[k];
		}
	}
	return f[1];
}

int ans[MAXN + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0); int p;
	for(p = 1; p <= SQRT && p <= n; p++)
		ans[p] = solve(p);
	for(; p <= n;) {
		int x = solve(p), l = p, r = n;
		while( l < r ) {
			int m = (l + r + 1) >> 1;
			if( solve(m) >= x )
				l = m;
			else r = m - 1;
		}
		for(; p <= l; p++) ans[p] = x;
	}
	
	for(int i=1;i<=n;i++) printf("%d\n", ans[i]);
}