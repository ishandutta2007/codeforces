#include <bits/stdc++.h>

const int N = 200;
const int M = N * N;

namespace fgraph{
	const int V = M;
	const int E = 20 * V;
	
	struct edge{
		int to, cap, flow;
		edge *nxt, *rev;
	}edges[E + 5], *adj[V + 5], *cur[V + 5], *ecnt = edges;
	void adde(int u, int v, int c) {
		edge *p = (++ecnt), *q = (++ecnt);
		(*p) = (edge){v, c, 0, adj[u], q}, adj[u] = p;
		(*q) = (edge){u, 0, 0, adj[v], p}, adj[v] = q;		
//		printf("%d %d %d\n", u, v, c);
	}
	
	int d[V + 5], s, t;
	int que[V + 5], hd, tl;
	bool relabel() {
		for(int i=s;i<=t;i++) d[i] = (1 << 30), cur[i] = adj[i];
		
		d[que[hd = tl = 1] = t] = 0;
		while( hd <= tl ) {
			int x = que[hd++];
			for(edge *p=adj[x];p;p=p->nxt) if( p->rev->cap > p->rev->flow )
				if( d[p->to] > d[x] + 1 ) d[que[++tl] = p->to] = d[x] + 1;
		}
		return d[s] != (1 << 30);
	}
	int aug(int x, int tot) {
		if( x == t ) return tot;
		
		int sum = 0;
		for(edge *&p=cur[x];p;p=p->nxt) {
			if( d[p->to] + 1 == d[x] ) {
				int del = aug(p->to, std::min(tot - sum, p->cap - p->flow));
				p->flow += del, p->rev->flow -= del, sum += del;
				if( sum == tot ) break;
			}
		}
		return sum;
	}
	int max_flow(int _s, int _t) {
		int flow = 0; s = _s, t = _t;
		while( relabel() ) flow += aug(s, 1 << 30);
		return flow;
	}
}

int a[N + 5][N + 5], d[2][M + 5], cnt;
char s[N + 5][N + 5];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++) {
		scanf("%s", s[i] + 1);
		for(int j=1;j<=m;j++) if( s[i][j] == '#' )
			a[i][j] = (++cnt);
	}
	
	int sum = 0, tot = 0;
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) if( s[i][j] == '#' && s[i + 1][j] == '#' ) {
		fgraph::adde(a[i][j], a[i + 1][j], 1);
		fgraph::adde(a[i + 1][j], a[i][j], 1);
		d[0][a[i][j]]++, d[0][a[i + 1][j]]++, sum++;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) if( s[i][j] == '#' && s[i][j + 1] == '#' ) {
		fgraph::adde(a[i][j], a[i][j + 1], 1);
		fgraph::adde(a[i][j + 1], a[i][j], 1);
		d[1][a[i][j]]++, d[1][a[i][j + 1]]++, sum++;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if( s[i][j] == '#' ) {
		fgraph::adde(0, a[i][j], d[0][a[i][j]]);
		fgraph::adde(a[i][j], cnt + 1, d[1][a[i][j]]);
		tot++;
	}
	printf("%d\n", tot - (sum - fgraph::max_flow(0, cnt + 1) / 2));
}