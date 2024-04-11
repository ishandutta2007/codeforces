#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 200000;

#define rep(G, x) for(Graph::edge *p=G.adj[x];p;p=p->nxt)
struct Graph{
	struct edge{
		edge *nxt; int to;
	}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
	Graph() {ecnt = edges;}
	void addedge(int u, int v) {
		edge *p = (++ecnt);
		p->to = v, p->nxt = adj[u], adj[u] = p;
		p = (++ecnt);
		p->to = u, p->nxt = adj[v], adj[v] = p;
	}
}G1, G2;

struct SAM{
	int fa[MAXN + 5], len[MAXN + 5], ch[26][MAXN + 5];
	int root, ncnt, lst;
	SAM() {root = ncnt = lst = 1; len[0] = -1;}
	void copy(int nq, int q) {
		for(int i=0;i<26;i++)
			ch[i][nq] = ch[i][q];
		fa[nq] = fa[q], len[nq] = len[q];
	}
	int extend(int x) {
		int p = lst, nw = (++ncnt);
		len[nw] = len[lst] + 1, lst = nw;
		while( p && ch[x][p] == 0 )
			ch[x][p] = nw, p = fa[p];
		if( !p ) fa[nw] = root;
		else {
			int q = ch[x][p];
			if( len[p] + 1 == len[q] )
				fa[nw] = q;
			else {
				int nq = (++ncnt); copy(nq, q);
				len[nq] = len[p] + 1, fa[q] = fa[nw] = nq;
				while( p && ch[x][p] == q )
					ch[x][p] = nq, p = fa[p];
			}
		}
		return nw;
	}
}S1, S2;

int cnt[MAXN + 5], fir[MAXN + 5], dfn[2*MAXN + 5], dep[MAXN + 5], dcnt;
void dfs1(int x, int f) {
	dfn[++dcnt] = x, fir[x] = dcnt, dep[x] = dep[f] + 1;
	rep(G2, x) {
		if( p->to == f ) continue;
		dfs1(p->to, x), dfn[++dcnt] = x;
	}
	cnt[x] = S2.len[x] + 1;
}
int lg[2*MAXN + 5], st[20][2*MAXN + 5];
void get_st() {
	for(int i=1;i<=dcnt;i++) st[0][i] = dfn[i];
	for(int i=2;i<=dcnt;i++) lg[i] = lg[i >> 1] + 1;
	for(int j=1;j<20;j++) {
		int t = (1 << (j - 1));
		for(int i=1;i+t<=dcnt;i++)
			st[j][i] = (dep[st[j-1][i]] < dep[st[j-1][i+t]] ? st[j-1][i] : st[j-1][i+t]);
	}
}
int lca(int x, int y) {
	int l = fir[x], r = fir[y];
	if( l > r ) swap(l, r);
	int k = lg[r - l + 1], p = (1 << k);
	return (dep[st[k][l]] < dep[st[k][r-p+1]] ? st[k][l] : st[k][r-p+1]);
}

struct segtree{
	struct node{
		node *ch[2];
		int lx, rx; ll res;
	}pl[20*MAXN + 5], *NIL, *ncnt;
	segtree() {
		NIL = ncnt = pl;
		NIL->ch[0] = NIL->ch[1] = NIL;
		NIL->lx = NIL->rx = NIL->res = 0;
	}
	node *newnode() {
		ncnt++;
		ncnt->ch[0] = ncnt->ch[1] = NIL;
		ncnt->lx = ncnt->rx = ncnt->res = 0;
		return ncnt;
	}
	void pushup(node *x) {
		x->lx = (x->ch[0] == NIL ? x->ch[1]->lx : x->ch[0]->lx);
		x->rx = (x->ch[1] == NIL ? x->ch[0]->rx : x->ch[1]->rx);
		x->res = x->ch[0]->res + x->ch[1]->res;
		if( x->ch[0] != NIL && x->ch[1] != NIL )
			x->res -= cnt[lca(dfn[x->ch[0]->rx], dfn[x->ch[1]->lx])];
	}
	void insert(node *&rt, int l, int r, int p) {
		if( rt == NIL ) rt = newnode();
		if( l == r ) {
			rt->lx = rt->rx = p, rt->res = cnt[dfn[p]];
			return ;
		}
		int m = (l + r) >> 1;
		if( p <= m ) insert(rt->ch[0], l, m, p);
		else insert(rt->ch[1], m + 1, r, p);
		pushup(rt);
	}
	node *merge(node *rt1, node *rt2) {
		if( rt1 == NIL ) return rt2;
		if( rt2 == NIL ) return rt1;
		rt1->ch[0] = merge(rt1->ch[0], rt2->ch[0]);
		rt1->ch[1] = merge(rt1->ch[1], rt2->ch[1]);
		pushup(rt1); return rt1;
	}
}T;
segtree::node *rt[MAXN + 5];

ll ans;
void dfs2(int x, int f) {
	rep(G1, x) {
		if( p->to == f ) continue;
		dfs2(p->to, x);
		rt[x] = T.merge(rt[x], rt[p->to]);
	}
	ans += rt[x]->res * (S1.len[x] - S1.len[f]);
}

char s[MAXN + 5]; int n;
int pos1[MAXN + 5], pos2[MAXN + 5];
ll get_num() {
	ll ret = 0;
	for(int i=1;i<=S1.ncnt;i++)
		ret += S1.len[i] - S1.len[S1.fa[i]];
	return ret;
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for(int i=1;i<=n;i++) pos1[i] = S1.extend(s[i] - 'a');
	for(int i=n;i>=1;i--) pos2[i] = S2.extend(s[i] - 'a');
	pos1[0] = pos2[n+1] = 1;
	for(int i=2;i<=S1.ncnt;i++) G1.addedge(S1.fa[i], i);
	for(int i=2;i<=S2.ncnt;i++) G2.addedge(S2.fa[i], i);
	ans = get_num();
	dfs1(1, 0), get_st();
	for(int i=0;i<=S1.ncnt;i++) rt[i] = T.NIL;
	for(int i=1;i<=n;i++) T.insert(rt[pos1[i-1]], 1, dcnt, fir[pos2[i+1]]);
	dfs2(1, 0);
	printf("%lld\n", ans);
}