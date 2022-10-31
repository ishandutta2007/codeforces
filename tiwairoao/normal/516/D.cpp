#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

std::vector<std::pair<int, int> >G[N + 5];
void adde(int u, int v, int w) {
	G[u].push_back(std::make_pair(v, w));
	G[v].push_back(std::make_pair(u, w));
}

ll dep[N + 5];
void dfs1(int x, int fa) {
	if( !fa ) dep[x] = 0;
	for(auto to : G[x]) if( to.first != fa )
		dep[to.first] = dep[x] + to.second, dfs1(to.first, x);
}

ll d[N + 5]; int ch[2][N + 5], siz[N + 5], dis[N + 5];
int merge(int x, int y) {
	if( !x || !y ) return x + y;
	if( d[x] < d[y] ) std::swap(x, y);
	siz[x] += siz[y], ch[1][x] = merge(ch[1][x], y);
	if( dis[ch[1][x]] > dis[ch[0][x]] ) std::swap(ch[1][x], ch[0][x]);
	dis[x] = dis[ch[1][x]] + 1;
	return x;
}

int rt[N + 5], ans, n, root; ll l;
void dfs2(int x, int fa) {
	rt[x] = x;
	for(auto to : G[x]) if( to.first != fa )
		dfs2(to.first, x), rt[x] = merge(rt[x], rt[to.first]);
	while( d[rt[x]] > d[x] + l ) rt[x] = merge(ch[0][rt[x]], ch[1][rt[x]]);
	ans = std::max(ans, siz[rt[x]]);
}
int solve() {
	for(int i=1;i<=n;i++) ch[0][i] = ch[1][i] = 0, siz[i] = dis[i] = 1;
	ans = 0, dfs2(root, 0); return ans;
}
int main() {
	int m; scanf("%d", &n);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d", &u, &v, &w), adde(u, v, w);
	
	dfs1(1, 0); int p = std::max_element(dep + 1, dep + n + 1) - dep;
	dfs1(p, 0); int q = std::max_element(dep + 1, dep + n + 1) - dep;
	for(int i=1;i<=n;i++) d[i] = std::max(d[i], dep[i]);
	dfs1(q, 0); for(int i=1;i<=n;i++) d[i] = std::max(d[i], dep[i]);
	root = std::min_element(d + 1, d + n + 1) - d;
	
	scanf("%d", &m);
	for(int i=1;i<=m;i++)
		scanf("%lld", &l), printf("%d\n", solve());
}