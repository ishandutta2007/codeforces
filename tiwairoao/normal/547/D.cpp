#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;

struct edge{
	int to, id; bool tag;
	edge *nxt, *rev;
}edges[4*N + 5], *adj[2*N + 5], *ecnt = edges;

void addedge(int u, int v, int i) {
	edge *p = (++ecnt), *q = (++ecnt);
	p->to = v, p->id = i, p->tag = false, p->nxt = adj[u], adj[u] = p;
	q->to = u, q->id = i, q->tag = false, q->nxt = adj[v], adj[v] = q;
	p->rev = q, q->rev = p;
}

bool ans[N + 5];
void dfs(int x) {
	for(;adj[x];) {
		edge *p = adj[x]; adj[x] = adj[x]->nxt;
		if( p->tag ) continue;
		p->tag = p->rev->tag = true;
		ans[p->id] = (p->to > N);
		dfs(p->to);
	}
}

int deg[2*N + 5];
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		addedge(x, N + y, i), deg[x]++, deg[N + y]++;
	}
	for(int i=1;i<=2*N;i++)
		if( deg[i] & 1 ) addedge(0, i, 0);
	
	for(int i=0;i<=2*N;i++) dfs(i);
	for(int i=1;i<=n;i++)
		putchar(ans[i] ? 'b' : 'r');
}