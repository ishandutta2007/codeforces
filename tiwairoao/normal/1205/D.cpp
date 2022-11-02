#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2000;
struct Graph{
	struct edge{
		int to, val, tag;
		edge *nxt, *rev;
	}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
	Graph() {ecnt = &edges[0];}
	void addedge(int u, int v, bool flag = true) {
		edge *p = (++ecnt), *q = (++ecnt);
		p->to = v, p->tag = flag, p->nxt = adj[u], adj[u] = p;
		q->to = u, q->tag = flag, q->nxt = adj[v], adj[v] = q;
		p->rev = q, q->rev = p;
//		printf("! %d %d %d\n", u, v, flag);
	}
}G1, G2;
int fa[MAXN + 5], n, m;
void rebuild(int x, int f) {
	int lst = x; fa[x] = f;
	for(Graph::edge *p=G1.adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		rebuild(p->to, x);
		int nw = (++m);
		G2.addedge(lst, nw, false);
		G2.addedge(nw, p->to);
		lst = nw;
	}
}
int siz[MAXN + 5];
void update(Graph::edge *&a, Graph::edge *b, int tot) {
	if( a == NULL ) a = b;
	else if( b != NULL && max(siz[a->to], tot-siz[a->to]) > max(siz[b->to], tot-siz[b->to]) )
		a = b;
}
Graph::edge *get_mid_edge(int x, int f, int tot) {
	Graph::edge *ret = NULL; siz[x] = (x <= n);
	for(Graph::edge *p=G2.adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		update(ret, get_mid_edge(p->to, x, tot), tot);
		update(ret, p, tot);
		siz[x] += siz[p->to];
	}
	return ret;
}
int cnt, type, tag;
void dfs(int x, int f, bool flag, int k) {
	if( x <= n && (!flag) ) cnt++;
	for(Graph::edge *p=G2.adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		if( !p->tag && p->to < x ) dfs(p->to, x, flag, k);
	}
	for(Graph::edge *p=G2.adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		if( p->tag ) {
			p->val = p->rev->val = (cnt - k)*type;
			dfs(p->to, x, false, cnt);
		}
		else if( !p->tag && p->to > x ) dfs(p->to, x, flag, k);
	}
}
int main() {
	scanf("%d", &n); m = n;
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		G1.addedge(u, v);
	}
	rebuild(1, 0);
	Graph::edge *e = get_mid_edge(1, 0, n);
	if( e ) {
		if( e->tag ) e->val = e->rev->val = 1;
		type = 1, cnt = 1, dfs(e->to, e->rev->to, true, 0);
		type = siz[e->to], cnt = 1, dfs(e->rev->to, e->to, true, 0);
	}
	for(int i=2;i<=n;i++)
		for(Graph::edge *p=G2.adj[i];p;p=p->nxt)
			if( p->tag ) printf("%d %d %d\n", i, fa[i], p->val);
}