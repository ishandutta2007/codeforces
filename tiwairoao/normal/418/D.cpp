#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100000;
const int INF = (1<<30);
struct edge{
	edge *nxt; int to;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt=&edges[0];
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
int siz[MAXN + 5], dep[MAXN + 5], hvy[MAXN + 5], fa[MAXN + 5];
void dfs1(int x, int f) {
	siz[x] = 1, dep[x] = dep[f] + 1, hvy[x] = 0, fa[x] = f;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		dfs1(p->to, x);
		siz[x] += siz[p->to];
		if( siz[p->to] > siz[hvy[x]] )
			hvy[x] = p->to;
	}
}
int top[MAXN + 5], dfn[MAXN + 5], tid[MAXN + 5], dcnt = 0;
void dfs2(int x, int tp) {
	top[x] = tp, dfn[++dcnt] = x, tid[x] = dcnt;
	if( hvy[x] ) dfs2(hvy[x], tp);
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa[x] || p->to == hvy[x] ) continue;
		dfs2(p->to, p->to);
	}
}
int f[MAXN + 5], g[MAXN + 5], h[MAXN + 5];
int pf[MAXN + 5], pg[MAXN + 5];
void dfs3(int x) {
	f[x] = g[x] = h[x] = 0;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa[x] ) continue;
		dfs3(p->to);
		if( f[p->to] + 1 > f[x] ) {
			h[x] = g[x], g[x] = f[x], f[x] = f[p->to] + 1;
			pg[x] = pf[x], pf[x] = p->to;
		}
		else if( f[p->to] + 1 > g[x] ) {
			h[x] = g[x], g[x] = f[p->to] + 1;
			pg[x] = p->to;
		}
		else if( f[p->to] + 1 > h[x] )
			h[x] = f[p->to] + 1;
	}
}
int lca(int u, int v) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u, v);
		u = fa[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u, v);
	return v;
}
int get_fa(int u, int d) {
	while( dep[top[u]] > d )
		u = fa[top[u]];
	return dfn[tid[u] - (dep[u] - d)];
}
int st[2][20][MAXN + 5], lg[MAXN + 5];
void get_st() {
	for(int i=1;i<=dcnt;i++) {
		if( pf[dfn[i]] == hvy[dfn[i]] )
			st[0][0][i] = g[dfn[i]] - dep[dfn[i]], st[1][0][i] = g[dfn[i]] + dep[dfn[i]];
		else st[0][0][i] = f[dfn[i]] - dep[dfn[i]], st[1][0][i] = f[dfn[i]] + dep[dfn[i]];
	}
	for(int j=1;j<20;j++) {
		int t = (1<<(j-1));
		for(int i=1;i+t<=dcnt;i++)
			st[0][j][i] = max(st[0][j-1][i], st[0][j-1][i+t]), st[1][j][i] = max(st[1][j-1][i], st[1][j-1][i+t]);
	}
	for(int i=2;i<=dcnt;i++)
		lg[i] = lg[i>>1] + 1;
}
int rmq(int le, int ri, bool type) {
	if( le > ri ) return -INF;
	int k = lg[ri-le+1], l = (1<<k);
	return max(st[type][k][le], st[type][k][ri-l+1]); 
}
int query(int u, int v, bool type) {
	int ret = -INF;
	while( top[u] != top[v] ) {
		ret = max(ret, rmq(tid[top[u]], tid[u]-1, type));
		u = top[u];
		if( pf[fa[u]] == u )
			ret = max(ret, g[fa[u]] + (type ? 1 : -1)*dep[fa[u]]);
		else ret = max(ret, f[fa[u]] + (type ? 1 : -1)*dep[fa[u]]);
		u = fa[u];
	}
	return max(ret, rmq(tid[v], tid[u]-1, type));
}
int main() {
	int n, m; scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs1(1, 0), dfs2(1, 1), dfs3(1), get_st();
	scanf("%d", &m);
	for(int i=1;i<=m;i++) {
		int a, b; scanf("%d%d", &a, &b);
		if( dep[a] < dep[b] ) swap(a, b);
		int l = lca(a, b), dis = dep[a] + dep[b] - 2*dep[l];
		int mid = get_fa(a, dep[a] - (dis - 1)/2), ans = max(f[a], dep[a] + query(a, mid, 0));
		if( b == l )
			ans = max(ans, max(dep[b] + query(b, 1, 0), -dep[b] + query(mid, b, 1)));
		else {
			int p = get_fa(a, dep[l] + 1), q = get_fa(b, dep[l] + 1);
			ans = max(ans, -dep[l] + query(mid, p, 1) + dep[b] - dep[l]);
			ans = max(ans, dep[b] + query(b, q, 0));
			ans = max(ans, dep[b] + query(l, 1, 0));
			ans = max(ans, f[b]);
			if( pf[l] == p ) {
				if( pg[l] == q )
					ans = max(ans, dep[b] - dep[l] + h[l]);
				else ans = max(ans, dep[b] - dep[l] + g[l]);
			}
			else if( pf[l] == q ) {
				if( pg[l] == p )
					ans = max(ans, dep[b] - dep[l] + h[l]);
				else ans = max(ans, dep[b] - dep[l] + g[l]);
			}
			else ans = max(ans, dep[b] - dep[l] + f[l]);
		}
		printf("%d\n", ans);
	}
}