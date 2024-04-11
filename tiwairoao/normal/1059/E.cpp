#include<cstdio>
typedef long long ll;
const int MAXN = 100000;
const ll INF = (1LL<<60);
struct edge{
	int to;
	edge *nxt;
}edges[MAXN + 5], *adj[MAXN + 5], *ecnt=&edges[0];
void addedge(int u, int v) {
	edge *p=(++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
}
int n, L; ll w[MAXN + 5], S;
int fa[MAXN + 5], dep[MAXN + 5], siz[MAXN + 5];
int fir[MAXN + 5], dfn[MAXN + 5], top[MAXN + 5], dcnt = 0;
void dfs1(int rt, int pre) {
	fa[rt] = pre, dep[rt] = dep[pre] + 1, siz[rt] = 1;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == pre ) continue;
		dfs1(p->to, rt);
		siz[rt] += siz[p->to];
	}
}
void dfs2(int rt, int tp) {
	top[rt] = tp, fir[rt] = (++dcnt), dfn[dcnt] = rt;
	int hvy = 0;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == fa[rt] ) continue;
		if( hvy == 0 || siz[p->to] > siz[hvy] )
			hvy = p->to;
	}
	if( !hvy ) return ;
	dfs2(hvy, tp);
	for(edge *p=adj[rt];p!=NULL;p=p->nxt)
		if( p->to != fa[rt] && p->to != hvy )
			dfs2(p->to, p->to);
}
struct node{
	int le, ri;
	bool tag;
	ll sum;
}tree[4*MAXN + 5];
void PushUp(int x) {
	tree[x].sum = tree[x<<1].sum + tree[x<<1|1].sum;
}
void Build(int x, int l, int r) {
	tree[x].le = l, tree[x].ri = r;
	if( l == r ) {
		tree[x].sum = w[dfn[l]];
		return ;
	}
	int Mid = (l + r) >> 1;
	Build(x<<1, l, Mid);
	Build(x<<1|1, Mid+1, r);
	PushUp(x);
}
void Modify(int x, int l, int r) {
	if( l > tree[x].ri || r < tree[x].le )
		return ;
	if( l <= tree[x].le && tree[x].ri <= r ) {
		tree[x].tag = true;
		return ;
	}
	if( tree[x].tag ) return ;
	Modify(x<<1, l, r);
	Modify(x<<1|1, l, r);
}
bool Query(int x, int pos) {
	if( pos > tree[x].ri || pos < tree[x].le )
		return false;
	if( pos == tree[x].le && pos == tree[x].ri ) return tree[x].tag;
	if( tree[x].tag ) return true;
	else return Query(x<<1, pos) || Query(x<<1|1, pos);
}
void TModify(int u, int v) {
	while( top[u] != top[v] ) {
		if( dep[top[u]] > dep[top[v]] ) {
			Modify(1, fir[top[u]], fir[u]);
			u = fa[top[u]];
		}
		else {
			Modify(1, fir[top[v]], fir[v]);
			v = fa[top[v]];
		}
	}
	if( dep[u] > dep[v] )
		Modify(1, fir[v], fir[u]);
	else Modify(1, fir[u], fir[v]);
}
int fa1[MAXN + 5][25];
ll sum[MAXN + 5][25];
void dfs(int rt) {
	for(int i=1;i<20;i++) {
		fa1[rt][i] = fa1[fa1[rt][i-1]][i-1];
		if( sum[rt][i-1] != INF && sum[fa1[rt][i-1]][i-1] != INF )
			sum[rt][i] = sum[rt][i-1] + sum[fa1[rt][i-1]][i-1];
		else sum[rt][i] = INF;
	}
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		fa1[p->to][0] = rt;
		sum[p->to][0] = w[rt];
		dfs(p->to);
	}
}
int UpTo(int u, ll lim, int dep) {
	dep--; lim -= w[u];
    for(int i=19;i>=0;i--) {
        if( sum[u][i] <= lim && dep >= (1<<i) ) {
            lim -= sum[u][i];
            dep -= (1<<i);
            u = fa1[u][i];
        }
    }
    return u;
}
int ans = 0;
void dfs3(int rt) {
	for(edge *p=adj[rt];p!=NULL;p=p->nxt)
		dfs3(p->to);
	if( !Query(1, fir[rt]) ) {
		TModify(rt, UpTo(rt, S, L));
		ans++;
	}
}
int main() {
	scanf("%d%d%I64d", &n, &L, &S);
	for(int i=1;i<=n;i++)
		scanf("%I64d", &w[i]);
	for(int i=2;i<=n;i++) {
		int p;
		scanf("%d", &p);
		addedge(p, i);
	}
	for(int i=1;i<=n;i++) {
		if( w[i] > S ) {
			printf("%d\n", -1);
			return 0;
		}
	}
	for(int i=0;i<20;i++) {
        sum[0][i] = (1LL<<60);
        fa1[0][i] = 0;
    }
    sum[1][0] = (1LL<<60);
	dfs1(1, 0); dfs2(1, 1); Build(1, 1, n); dfs(1); dfs3(1);
	printf("%d\n", ans);
}