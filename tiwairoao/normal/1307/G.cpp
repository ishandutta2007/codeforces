#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
#define pr make_pair
#define fi first
#define se second

namespace fgraph{
	const int MAXV = 50;
	const int MAXE = 10*MAXV*MAXV;
	const int INF = (1 << 30);
	
	struct edge{
		int to, cap, flow, cost;
		edge *nxt, *rev;
	}edges[MAXE + 5], *adj[MAXV + 5], *cur[MAXV + 5], *ecnt = edges;
	void addedge(int u, int v, int c, int w) {
		edge *p = (++ecnt), *q = (++ecnt);
		(*p) = (edge){v, c, 0, w, adj[u], q}, adj[u] = p;
		(*q) = (edge){u, 0, 0, -w, adj[v], p}, adj[v] = q;
	}
	int d[MAXV + 5], h[MAXV + 5], s, t;
	bool relabel() {
		for(int i=s;i<=t;i++)
			h[i] += d[i], d[i] = INF, cur[i] = adj[i];
		priority_queue<pii, vector<pii>, greater<pii> >que;
		que.push(pr(d[t] = 0, t));
		while( !que.empty() ) {
			int k = que.top().fi, x = que.top().se; que.pop();
			if( k != d[x] ) continue;
			for(edge *p=adj[x];p;p=p->nxt) {
				if( p->rev->cap > p->rev->flow ) {
					int dis = k + p->rev->cost + (h[x] - h[p->to]);
					if( dis < d[p->to] ) que.push(pr(d[p->to] = dis, p->to));
				}
			}
		}
		return d[s] != INF;
	}
	bool vis[MAXV + 5];
	int aug(int x, int tot) {
		if( x == t ) return tot;
		vis[x] = true; int sum = 0;
		for(edge *&p=cur[x];p;p=p->nxt) {
			int dis = d[p->to] + p->cost + (h[p->to] - h[x]);
			if( d[x] == dis && !vis[p->to] && p->cap > p->flow ) {
				int del = aug(p->to, min(tot - sum, p->cap - p->flow));
				sum += del, p->flow += del, p->rev->flow -= del;
				if( sum == tot ) break;
			}
		}
		vis[x] = false; return sum;
	}
}

int f[55];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		fgraph::addedge(u, v, 1, w);
	}
	int cnt = 0;
	fgraph::s = 1, fgraph::t = n;
	for(cnt = 0;fgraph::relabel();cnt++)
		f[cnt + 1] = f[cnt] + fgraph::d[1] + fgraph::h[1], fgraph::aug(1, 1);
	
	int q; scanf("%d", &q);
	for(int i=1;i<=q;i++) {
		int x; scanf("%d", &x);
		
		double ans = 1E12;
		for(int j=1;j<=cnt;j++)
			ans = min(ans, 1.0*(x + f[j])/j);
		
		printf("%.9f\n", ans);
	}
}