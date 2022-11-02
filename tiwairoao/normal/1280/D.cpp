#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pil;

const int MAXN = 3000;

struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
void clear(int n) {
	for(int i=1;i<=n;i++)
		adj[i] = NULL;
	ecnt = edges;
}

int siz[MAXN + 5], n, m;
ll a[MAXN + 5], b[MAXN + 5];
pil dp[MAXN + 5][MAXN + 5], t[MAXN + 5];

void dfs(int x, int f) {
	siz[x] = 1, dp[x][1] = make_pair(0, b[x] - a[x]);
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		dfs(p->to, x);
		int t1 = min(siz[x], m), t2 = min(siz[p->to], m), t3 = min(siz[x] + siz[p->to], m);
		for(int i=t1;i>=1;i--) t[i] = dp[x][i];
		for(int i=t3;i>=1;i--) dp[x][i] = make_pair(-1, -1);
		for(int i=t1;i>=1;i--)
			for(int j=t2;j>=1;j--) {
				if( i + j <= t3 ) {
					int d = (dp[p->to][j].second > 0);
					dp[x][i+j] = max(dp[x][i+j], make_pair(t[i].first + dp[p->to][j].first + d, t[i].second));
				}
				if( i + j - 1 <= t3 ) {
					dp[x][i+j-1] = max(dp[x][i+j-1], make_pair(t[i].first + dp[p->to][j].first, t[i].second + dp[p->to][j].second));
				}
			}
		siz[x] += siz[p->to];
	}
}

void solve() {
	scanf("%d%d", &n, &m), clear(n);
	for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
	for(int i=1;i<=n;i++) scanf("%lld", &b[i]);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0);
	printf("%d\n", dp[1][m].first + (dp[1][m].second > 0));
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}