#include<cstdio>
#include<vector>
#include<iostream> 
#include<algorithm>
using namespace std;
const int MAXN = 20000;
const int MAXM = 10000;
const int MAXV = 200000;
const int MAXE = 10000000;
const int INF = (1<<30);
vector<pair<int, int> >G[MAXN + 5];
void add_edge(int u, int v, int n) {
	G[u].push_back(make_pair(v, n));
	G[v].push_back(make_pair(u, n));
}
int siz[MAXN + 5], hvy[MAXN + 5], dep[MAXN + 5], fa[MAXN + 5], num[MAXN + 5];
int top[MAXN + 5], tid[MAXN + 5], dfn[MAXN + 5], dcnt = 0;
void dfs1(int rt, int pre) {
	siz[rt] = 1, hvy[rt] = 0, dep[rt] = dep[pre] + 1, fa[rt] = pre;
	for(int i=0;i<G[rt].size();i++) {
		int to = G[rt][i].first;
		if( to == pre ) continue;
		num[to] = G[rt][i].second;
		dfs1(to, rt); siz[rt] += siz[to];
		if( siz[to] > siz[hvy[rt]] )
			hvy[rt] = to;
	}
}
int vcnt = 0, S, T;
struct SegmentTree{
	int le, ri, num;
}tree[4*MAXN + 5];
void build_segtree(int x, int l, int r) {
	tree[x].le = l, tree[x].ri = r, tree[x].num = (++vcnt);
	if( l == r ) return ;
	int mid = (l + r) >> 1;
	build_segtree(x<<1, l, mid);
	build_segtree(x<<1|1, mid+1, r);
}
void dfs2(int rt, int tp) {
	top[rt] = tp, dfn[++dcnt] = rt, tid[rt] = dcnt;
	if( !hvy[rt] ) return ;
	dfs2(hvy[rt], tp);
	for(int i=0;i<G[rt].size();i++) {
		int to = G[rt][i].first;
		if( to != fa[rt] && to != hvy[rt] )
			dfs2(to, to);
	}
}
struct edge{
	int to, cap, flow;
	edge *nxt, *rev;
}edges[MAXE + 5], *adj[MAXV + 5], *ecnt=&edges[0];
void addedge(int u, int v, int c) {
	edge *p = (++ecnt);
	p->to = v, p->cap = c, p->flow = 0;
	p->nxt = adj[u], adj[u] = p;
	edge *q = (++ecnt);
	q->to = u, q->cap = 0, q->flow = 0;
	q->nxt = adj[v], adj[v] = q;
	p->rev = q, q->rev = p;
}
int pos[MAXV + 5];
void build_edge_segtree(int x) {
	if( tree[x].le == tree[x].ri ) {
		addedge(tree[x].num, T, 1);
		pos[tree[x].num] = dfn[tree[x].le];
	}
	else  {
		addedge(tree[x].num, tree[x<<1].num, INF); build_edge_segtree(x<<1);
		addedge(tree[x].num, tree[x<<1|1].num, INF); build_edge_segtree(x<<1|1);
	}
}
void build_edge_human_segtree(int x, int l, int r, int h) {
	if( l <= tree[x].le && tree[x].ri <= r ) {
		addedge(h, tree[x].num, INF);
		return ;
	}
	if( l > tree[x].ri || r < tree[x].le )
		return ;
	build_edge_human_segtree(x<<1, l, r, h);
	build_edge_human_segtree(x<<1|1, l, r, h);
}
void build_edge_human_tree(int h, int u, int v) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] < dep[top[v]] ) swap(u, v);
		build_edge_human_segtree(1, tid[top[u]], tid[u], h);
		u = fa[top[u]];
	}
	if( dep[u] < dep[v] ) swap(u, v);
	build_edge_human_segtree(1, tid[v]+1, tid[u], h);
}
int d[MAXV + 5], vd[MAXV + 5];
int aug(int x, int tot) {
	if( x == T ) return tot;
	int mind = T+1, sum = 0;
	for(edge *p=adj[x];p!=NULL;p=p->nxt) {
		if( p->cap > p->flow ) {
			if( d[p->to] + 1 == d[x] ) {
				int del = aug(p->to, min(tot - sum, p->cap - p->flow));
				p->flow += del, p->rev->flow -= del, sum += del;
				if( d[S] >= T+1 ) return sum;
				if( sum == tot ) return sum;
			}
			mind = min(mind, d[p->to]);
		}
	}
	if( sum == 0 ) {
		vd[d[x]]--;
		if( !vd[d[x]] )
			d[S] = T+1;
		d[x] = mind + 1;
		vd[d[x]]++;
	}
	return sum;
}
int sap() {
	int flow = 0;
	while( d[S] < T+1 )
		flow += aug(S, INF);
	return flow;
}
bool vis[MAXV + 5];
void dfs3(int x) {
	vis[x] = true;
	for(edge *p=adj[x];p!=NULL;p=p->nxt)
		if( !vis[p->to] && p->cap > p->flow )
			dfs3(p->to);
}
vector<int>dog, human; 
void print() {
	dfs3(S);
	for(edge *p=adj[S];p!=NULL;p=p->nxt)
		if( !vis[p->to] ) human.push_back(p->to);
	printf("%d", human.size());
	for(int i=0;i<human.size();i++)
		printf(" %d", human[i]-vcnt);
	puts("");
	for(edge *p=adj[T];p!=NULL;p=p->nxt)
		if( vis[p->to] ) dog.push_back(p->to);
	printf("%d", dog.size());
	for(int i=0;i<dog.size();i++)
		printf(" %d", num[pos[dog[i]]]);
	puts("");
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1;i<n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add_edge(u, v, i);
	}
	dfs1(1, 0); dfs2(1, 1);
	build_segtree(1, 1, n);
	T = vcnt + m + 1;
	build_edge_segtree(1);
	for(int i=1;i<=m;i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(S, vcnt+i, 1);
		build_edge_human_tree(vcnt+i, x, y);
	}
	int ans = sap();
	printf("%d\n", ans);
	print();
}