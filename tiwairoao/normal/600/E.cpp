#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100000;

struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}

int siz[MAXN + 5], hvy[MAXN + 5];
void dfs1(int x, int f) {
	siz[x] = 1, hvy[x] = 0;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f ) {
			dfs1(p->to, x), siz[x] += siz[p->to];
			if( siz[hvy[x]] < siz[p->to] )
				hvy[x] = p->to;
		}
}
int b[MAXN + 5], c[MAXN + 5], mx; ll ans[MAXN + 5], res;
void add(int x) {
	b[x]++;
	if( b[x] > mx ) mx = b[x], res = x;
	else if( b[x] == mx ) res += x;
}
void update(int x, int f, int d) {
	if( d == 1 ) add(c[x]); else b[c[x]] = 0;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f ) update(p->to, x, d);
}
void dfs2(int x, int f, bool keep) {
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f && p->to != hvy[x] )
			dfs2(p->to, x, false);
	if( hvy[x] ) dfs2(hvy[x], x, true);
	add(c[x]);
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f && p->to != hvy[x] )
			update(p->to, x, 1);
	ans[x] = res;
	if( !keep ) update(x, f, -1), res = 0, mx = 0;
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) scanf("%d", &c[i]);
	for(int i=1;i<n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	dfs1(1, 0), dfs2(1, 0, false);
	for(int i=1;i<=n;i++) printf("%lld ", ans[i]);
}