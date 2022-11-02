#include<cstdio>
#include<cstdlib>
const int MAXN = 200000;
struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = &edges[0];
int clr[MAXN + 5], n, k;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
int dep[MAXN + 5];
void dfs1(int x, int f) {
	dep[x] = dep[f] + 1;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f ) dfs1(p->to, x);
}
int get_pos(int x) {
	dfs1(x, 0); int mx = x;
	for(int i=1;i<=n;i++)
		if( dep[i] > dep[mx] ) mx = i;
	return mx;
}
bool tag[MAXN + 5];
void dfs2(int x, int f) {
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f ) {
			dfs2(p->to, x);
			tag[x] |= tag[p->to];
		}
}
int f[MAXN + 5], g[MAXN + 5];
int nxt(int x) {return (x == k) ? 1 : x + 1;}
int lst(int x) {return (x == 1) ? k : x - 1;}
void dfs4(int x, int fa, int type) {
	if( type ) clr[x] = nxt(clr[fa]);
	else clr[x] = lst(clr[fa]);
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != fa ) {
			dfs4(p->to, x, type);
			if( f[p->to] + 1 > f[x] )
				g[x] = f[x], f[x] = f[p->to] + 1;
			else if( f[p->to] + 1 > g[x] )
				g[x] = f[p->to] + 1;
		}
	if( f[x] && g[x] && f[x] + g[x] + 1 >= k ) {
		puts("No");
		exit(0);
	}
}
int mxdep;
void dfs3(int x, int fa) {
	clr[x] = nxt(clr[fa]); f[x] = g[x] = 0;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != fa ) {
			if( tag[p->to] ) dfs3(p->to, x);
			else {
				if( dep[x] <= mxdep - dep[x] + 1 )
					dfs4(p->to, x, 0);
				else dfs4(p->to, x, 1);
				if( f[p->to] + 1 > f[x] )
					g[x] = f[x], f[x] = f[p->to] + 1;
				else if( f[p->to] + 1 > g[x] )
					g[x] = f[p->to] + 1;
			}
		}
	if( f[x] && g[x] && f[x] + g[x] + 1 >= k ) {
		puts("No");
		exit(0);
	}
	if( f[x] && f[x] + dep[x] >= k && f[x] + mxdep - dep[x] + 1 >= k ) {
		puts("No");
		exit(0);
	}
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	if( k == 2 ) {
		puts("Yes"), get_pos(1);
		for(int i=1;i<=n;i++)
			printf("%d ", (dep[i] & 1) + 1);
		return 0;
	}
	int p = get_pos(1), q = get_pos(p); mxdep = dep[q];
	tag[q] = true, dfs2(p, 0), clr[0] = k, dfs3(p, 0);
	puts("Yes");
	for(int i=1;i<=n;i++)
		printf("%d ", clr[i]);
	puts("");
}