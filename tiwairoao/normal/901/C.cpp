#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 300000;
struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
int dfn[MAXN + 5], low[MAXN + 5], dcnt = 0;
int stk[MAXN + 5], tp;
vector<int>v[MAXN + 5];
void dfs(int x, int fa) {
	dfn[x] = low[x] = (++dcnt);
	stk[++tp] = x;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == fa ) continue;
		if( !dfn[p->to] )
			dfs(p->to, x), low[x] = min(low[x], low[p->to]);
		else low[x] = min(low[x], dfn[p->to]);
	}
	if( low[x] >= dfn[x] ) {
		int mn = x, mx = x;
		do {
			mn = min(mn, stk[tp]);
			mx = max(mx, stk[tp]);
		}while( stk[tp--] != x );
		if( mn != mx ) v[mx].push_back(mn);
	}
}
struct segtree{
	#define lch (x<<1)
	#define rch (x<<1|1)
	struct node{
		int l, r;
		ll tg, sum;
	}t[4*MAXN + 5];
	void build(int x, int l, int r) {
		t[x].l = l, t[x].r = r;
		t[x].tg = t[x].sum = 0;
		if( l == r ) return ;
		int mid = (l + r) >> 1;
		build(lch, l, mid), build(rch, mid + 1, r);
	}
	void pushdown(int x) {
		if( t[x].tg ) {
			t[lch].tg += t[x].tg, t[lch].sum += 1LL*(t[lch].r - t[lch].l + 1)*t[x].tg;
			t[rch].tg += t[x].tg, t[rch].sum += 1LL*(t[rch].r - t[rch].l + 1)*t[x].tg;
			t[x].tg = 0;
		}
	}
	void pushup(int x) {
		t[x].sum = t[lch].sum + t[rch].sum;
	}
	void modify(int x, int l, int r, int k) {
		if( l > t[x].r || r < t[x].l )
			return ;
		if( l <= t[x].l && t[x].r <= r ) {
			t[x].tg += k, t[x].sum += 1LL*(t[x].r - t[x].l + 1)*k;
			return ;
		}
		pushdown(x);
		modify(lch, l, r, k), modify(rch, l, r, k);
		pushup(x);
	}
	ll query(int x, int l, int r) {
		if( l > t[x].r || r < t[x].l )
			return 0;
		if( l <= t[x].l && t[x].r <= r )
			return t[x].sum;
		pushdown(x);
		return query(lch, l, r) + query(rch, l, r);
	}
}T;
vector<pair<int, int> >qry[MAXN + 5];
ll ans[MAXN + 5];
int main() {
	int n, m, q; scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int a, b; scanf("%d%d", &a, &b);
		addedge(a, b);
	}
	for(int i=1;i<=n;i++)
		if( !dfn[i] ) dfs(i, 0);
	scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int l, r; scanf("%d%d", &l, &r);
		qry[r].push_back(make_pair(l, i));
	}
	int p = 0; T.build(1, 1, n);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<v[i].size();j++)
			p = max(p, v[i][j]);
		T.modify(1, p + 1, i, 1);
		for(int j=0;j<qry[i].size();j++)
			ans[qry[i][j].second] = T.query(1, qry[i][j].first, i);
	}
	for(int i=1;i<=q;i++)
		printf("%lld\n", ans[i]);
}