#include <cstdio>

const int MAXN = 3000;

struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
#define rep(x) for(edge *p=adj[x];p;p=p->nxt)

bool vis[MAXN + 5], tag[MAXN + 5];
int a[MAXN + 5], cnt, siz;
void dfs1(int x, int f) {
	vis[a[++cnt] = x] = true;
	rep(x) {
		if( p->to == f ) continue;
		if( vis[p->to] ) {
			siz = 0;
			for(int j=cnt;;j--) {
				tag[a[j]] = true, siz++;
				if( a[j] == p->to ) break;
			}
		}
		else dfs1(p->to, x);
		if( siz ) break;
	}
	a[cnt--] = 0, vis[x] = false;
}

double ans;

double get(int s, int d) {
	if( s >= 2 ) {
		int p = s - 2, q = siz - s, r = d - s + 2;
		return 1.0 / (r + p) + 1.0 / (r + q) - 1.0 / (r + p + q);
	}
	else return 1.0 / d;
}
void dfs2(int x, int s, int d) {
	vis[x] = true, d++;
	if( tag[x] ) s++;
	ans += get(s, d);
	rep(x) {
		if( vis[p->to] ) continue;
		dfs2(p->to, s, d);
	}
}

int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int a, b; scanf("%d%d", &a, &b);
		addedge(a + 1, b + 1);
	}
	dfs1(1, 0);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) vis[j] = false;
		dfs2(i, 0, 0);
	}
	printf("%.9f\n", ans);
}