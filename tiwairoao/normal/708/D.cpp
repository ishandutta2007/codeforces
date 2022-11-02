#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV = 400 + 5;
const int MAXE = 20000 + 5;
const int INF = int(1E9);
struct FlowGraph{
	struct edge{
		int to, flow, cap, dis;
		edge *nxt, *rev;
	}edges[MAXE], *adj[MAXV], *cur[MAXV], *ecnt;
	int s, t, cost, dist[MAXV];
	void init() {
		ecnt = &edges[0];
		for(int i=0;i<MAXV;i++) adj[i] = NULL;
	}
	void addedge(int u, int v, int c, int w) {
		edge *p = (++ecnt), *q = (++ecnt);
		p->to = v, p->flow = 0, p->cap = c, p->dis = w;
		p->nxt = adj[u], adj[u] = p;
		q->to = u, q->flow = 0, q->cap = 0, q->dis = -w;
		q->nxt = adj[v], adj[v] = q;
		p->rev = q, q->rev = p;
	}
	bool inque[MAXV];
	bool relabel() {
		queue<int>que;
		for(int i=0;i<MAXV;i++) dist[i] = INF, cur[i] = adj[i];
		que.push(s); dist[s] = 0, inque[s] = true;
		while( !que.empty() ) {
			int f = que.front(); que.pop(); inque[f] = false;
			for(edge *p=adj[f];p;p=p->nxt) {
				if( p->cap > p->flow && dist[f] + p->dis < dist[p->to] ) {
					dist[p->to] = dist[f] + p->dis;
					if( !inque[p->to] ) {
						que.push(p->to);
						inque[p->to] = true;
					}
				}
			}
		}
		return !(dist[t] == INF);
	}
	bool vis[MAXV];
	int aug(int x, int tot) {
		if( x == t ) {
			cost += tot*dist[x];
			return tot;
		}
		int sum = 0; vis[x] = true;
		for(edge *&p=cur[x];p;p=p->nxt) {
			if( p->cap > p->flow && !vis[p->to] && dist[p->to] == dist[x] + p->dis ) {
				int del = aug(p->to, min(tot-sum, p->cap-p->flow));
				p->flow += del, p->rev->flow -= del, sum += del;
				if( sum == tot ) break;
			}
		}
		vis[x] = false;
		return sum;
	}
	int min_cost_max_flow(int _s, int _t) {
		s = _s, t = _t; int flow = 0; cost = 0;
		while( relabel() )
			flow += aug(s, INF);
		return flow;
	}
}G;
int deg[MAXV];
int main() {
	G.init(); int n, m;
	scanf("%d%d", &n, &m);
	int s = 1, t = n, ss = 0, tt = n + 1, ans = 0;
	for(int i=1;i<=m;i++) {
		int u, v, c, f; scanf("%d%d%d%d", &u, &v, &c, &f);
		if( c < f ) {
			G.addedge(v, u, c, 1);
			G.addedge(v, u, f - c, 0);
			G.addedge(u, v, INF, 2);
			ans += f - c;
			deg[u] += f, deg[v] -= f;
		}
		else {
			G.addedge(v, u, f, 1);
			G.addedge(u, v, c - f, 1);
			G.addedge(u, v, INF, 2);
			deg[u] += f, deg[v] -= f;
		}
	}
	for(int i=1;i<=n;i++) {
		if( deg[i] < 0 ) G.addedge(ss, i, -deg[i], 0);
		if( deg[i] > 0 ) G.addedge(i, tt, deg[i], 0);
	}
	G.addedge(t, s, INF, 0);
	G.min_cost_max_flow(ss, tt);
	printf("%d\n", ans + G.cost);
}