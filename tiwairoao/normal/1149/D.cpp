#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 70;
const int MAXM = 200;
const int INF = int(1E9);
struct edge{
	int to, dis;
	edge *nxt;
}edges[2*MAXM + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v, int w) {
	edge *p = (++ecnt);
	p->to = v, p->dis = w, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->dis = w, p->nxt = adj[v], adj[v] = p;
}
struct node{
	int d, s, x;
	node(int _d=0, int _s=0, int _x=0) : d(_d), s(_s), x(_x) {}
	friend bool operator < (node a, node b) {
		return a.d > b.d;
	}
};
bool vis[MAXN][1<<17];
int d[MAXN][1<<17];
priority_queue<node>que;
int dis[MAXN + 5], fa[MAXN + 5], siz[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) fa[fx] = fy, siz[fy] += siz[fx];
}
int id[MAXN + 5], cnt, tot;
int u[MAXM + 5], v[MAXM + 5], w[MAXM + 5];
int n, m, a, b;
int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i=0;i<n;i++) fa[i] = i, siz[i] = 1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]), u[i]--, v[i]--;
		if( w[i] == a )
			addedge(u[i], v[i], w[i]), unite(u[i], v[i]);
	}
	for(int i=0;i<n;i++)
		if( find(i) == i ) {
			if( siz[i] >= 4 ) id[i] = (cnt++);
			else id[i] = -1;
		}
	for(int i=0;i<n;i++)
		id[i] = id[find(i)];
	tot = (1<<cnt);
	for(int i=0;i<n;i++) {
		for(int s=0;s<tot;s++)
			d[i][s] = INF;
		dis[i] = INF;
	}
	for(int i=1;i<=m;i++)
		if( w[i] == b && find(u[i]) != find(v[i]) )
			addedge(u[i], v[i], w[i]);
	que.push(node(0, 0, 0));
	while( !que.empty() ) {
		node x = que.top(); que.pop();
		if( vis[x.x][x.s] ) continue;
		dis[x.x] = min(dis[x.x], x.d);
		vis[x.x][x.s] = true;
		for(edge *p=adj[x.x];p;p=p->nxt) {
			if( p->dis == a && x.d + p->dis < d[p->to][x.s] )
				que.push(node(d[p->to][x.s]=x.d+p->dis, x.s, p->to));
			else if( id[p->to] == -1 || !((x.s >> id[p->to]) & 1) ) {
				int s = (x.s | (id[x.x] == -1 ? 0 : (1<<id[x.x])));
				if( x.d + p->dis < d[p->to][s] )
					que.push(node(d[p->to][s]=x.d+p->dis, s, p->to));
			}
		}
	}
	for(int i=0;i<n;i++)
		printf("%d%c", dis[i], (i == n - 1 ? '\n' : ' '));
}