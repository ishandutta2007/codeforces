#include<map>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rep(G, x) for(Graph::edge *p = G.adj[x];p;p = p->nxt)
#define pii pair<int, int>
#define fi first
#define se second
const int MAXN = 400000;
const int SQRT = 450;
struct Graph{
	struct edge{
		int to, id;
		edge *nxt;
	}edges[MAXN + 5], *adj[MAXN + 5], *ecnt;
	void clear(int n) {
		ecnt = &edges[0];
		for(int i=1;i<=n;i++)
			adj[i] = NULL;
	}
	void addedge(int u, int v, int id) {
		edge *p = (++ecnt);
		p->to = v, p->id = id, p->nxt = adj[u], adj[u] = p;
		p = (++ecnt);
		p->to = u, p->id = id, p->nxt = adj[v], adj[v] = p;
	}
}G;
int le[MAXN + 5], ri[MAXN + 5], num[MAXN + 5], bcnt;
void init(int m) {
	for(int i=1;i<=m;i++) {
		if( (i - 1) % SQRT == 0 )
			bcnt++, le[bcnt] = i;
		ri[bcnt] = i, num[i] = bcnt;
	}
}
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy )
		fa[fx] = fy;
}
vector<pii>e;
bool tag[MAXN + 5]; int tg2[MAXN + 5];
void update(int p) {
	if( tg2[p] == -1 ) {
		G.addedge(find(e[p].fi), find(e[p].se), p);
		tg2[p] = 1;
	}
	else tg2[p] ^= 1;
}
map<pii, int>mp;
int id(pii p) {
	if( p.fi > p.se ) swap(p.fi, p.se);
	if( mp.count(p) ) return mp[p];
	else {
		e.push_back(p);
		return mp[p] = e.size() - 1;
	}
}
bool vis[MAXN + 5];
void dfs(int x, bool f) {
	if( vis[x] == f ) return ;
	vis[x] = f;
	rep(G, x) {
		if( tg2[p->id] )
			dfs(p->to, f);
	}
}
bool query(int p) {
	dfs(find(e[p].fi), true);
	bool ret = vis[find(e[p].se)];
	dfs(find(e[p].fi), false);
	return ret;
}
bool lans[MAXN + 5];
int t[MAXN + 5], qry[2][MAXN + 5];
int n, m;
int main() {
	scanf("%d%d", &n, &m), init(m);
	for(int i=1;i<=m;i++) {
		int x, y;
		scanf("%d%d%d", &t[i], &x, &y);
		qry[0][i] = id(make_pair(x, y));
		x = x % n + 1, y = y % n + 1;
		qry[1][i] = id(make_pair(x, y));
	}
	int lastans = 0;
	for(int i=1;i<=bcnt;i++) {
		for(int j=1;j<le[i];j++) {
			tag[qry[lans[j]][j]] = false;
			tg2[qry[lans[j]][j]] = -1;
		}
		for(int j=le[i];j<=ri[i];j++) {
			tag[qry[0][j]] = tag[qry[1][j]] = true;
			tg2[qry[0][j]] = tg2[qry[1][j]] = -1;
		}
		for(int j=1;j<=n;j++) fa[j] = j;
		G.clear(n);
		for(int j=1;j<le[i];j++)
			if( t[j] == 1 && !tag[qry[lans[j]][j]] ) {
				if( tg2[qry[lans[j]][j]] == -1 ) tg2[qry[lans[j]][j]] = 1;
				else tg2[qry[lans[j]][j]] ^= 1;
			}
		for(int j=1;j<le[i];j++)
			if( t[j] == 1 && !tag[qry[lans[j]][j]] && tg2[qry[lans[j]][j]] ) {
				unite(e[qry[lans[j]][j]].fi, e[qry[lans[j]][j]].se);
			}
		for(int j=1;j<le[i];j++)
			if( t[j] == 1 && tag[qry[lans[j]][j]] )
				update(qry[lans[j]][j]);
		for(int j=le[i];j<=ri[i];j++) {
			if( t[j] == 1 )
				update(qry[lastans][j]), lans[j] = lastans;
			else lastans = lans[j] = query(qry[lastans][j]);
		}
	}
	for(int i=1;i<=m;i++)
		if( t[i] == 2 )
			putchar(char(lans[i]) + '0');
}