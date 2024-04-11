#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 200000;
const int MAXM = 500000;

struct edge{
	int to; edge *nxt;
}edges[2*MAXM + 5], *adj[MAXN + 5], *ecnt;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
void clear(int n) {
	ecnt = edges;
	for(int i=1;i<=n;i++)
		adj[i] = NULL;
}

ll ans;
int id[MAXN + 5];
bool vis[MAXN + 5];
pii p[MAXN + 5];
int cnt, tot;
int n, m, a, b;

void dfs(int x, int i) {
	id[x] = i, vis[x] = true;
	if( x != a && x != b ) tot++;
	for(edge *p=adj[x];p;p=p->nxt)
		if( !vis[p->to] ) dfs(p->to, i);
}

void solve() {
	scanf("%d%d%d%d", &n, &m, &a, &b), clear(n);
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	ans = 1LL*(n - 2)*(n - 3)/2;
	
	for(int i=1;i<=n;i++) vis[i] = false;
	vis[a] = true, cnt = 0;
	for(edge *p=adj[a];p;p=p->nxt)
		if( !vis[p->to] ) {
			tot = 0, dfs(p->to, ++cnt);
			ans -= 1LL*tot*(tot - 1)/2;
		}
	for(int i=1;i<=n;i++)
		if( i != a && i != b )
			p[i].first = id[i];
	
	for(int i=1;i<=n;i++) vis[i] = false;
	vis[b] = true, cnt = 0;
	for(edge *p=adj[b];p;p=p->nxt)
		if( !vis[p->to] ) {
			tot = 0, dfs(p->to, ++cnt);
			ans -= 1LL*tot*(tot - 1)/2;
		}
	for(int i=1;i<=n;i++)
		if( i != a && i != b )
			p[i].second = id[i];
	
	p[a] = p[b] = make_pair(-1, -1);
	sort(p + 1, p + n + 1);
	int nw = 1;
	for(int i=4;i<=n;i++) {
		if( p[i] != p[i-1] ) {
			ans += 1LL*nw*(nw - 1)/2;
			nw = 1;
		}
		else nw++;
	}
	ans += 1LL*nw*(nw - 1)/2;
	
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}