#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 600000;

struct edge{
	int to, dis;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = v, p->dis = w, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->dis = w, p->nxt = adj[v], adj[v] = p;
}
void clear(int n) {
	for(int i=1;i<=n;i++)
		adj[i] = NULL;
	ecnt = edges;
}

int siz[MAXN + 5], hvy[MAXN + 5];
int get_size(int x, int f) {
	siz[x] = 1;
	for(edge *p=adj[x];p;p=p->nxt)
		if( p->to != f )
			siz[x] += get_size(p->to, x);
	return siz[x];
}
ll G, B;
int get_G(int x, int f, int tot) {
	hvy[x] = tot - siz[x];
	int ret = -1;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		int t = get_G(p->to, x, tot);
		if( ret == -1 || hvy[ret] > hvy[t] )
			ret = t;
		hvy[x] = max(hvy[x], siz[p->to]);
		if( siz[p->to] % 2 )
			G += p->dis;
	}
	if( ret == -1 || hvy[ret] > hvy[x] )
		ret = x;
	return ret;
}

void dfs(int x, int f, ll d) {
	B += d;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		dfs(p->to, x, d + p->dis);
	}
}

void solve() {
	int k; scanf("%d", &k), k <<= 1, clear(k);
	for(int i=1;i<k;i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	G = B = 0;
	dfs(get_G(1, 0, get_size(1, 0)), 0, 0);
	printf("%lld %lld\n", G, B);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}