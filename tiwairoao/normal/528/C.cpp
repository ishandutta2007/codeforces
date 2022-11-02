#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int MAXM = 300000;

struct edge{
	int to; edge *nxt, *rev;
}edges[2*MAXM + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	if( u != v ) {
		edge *p = (++ecnt), *q = (++ecnt);
		p->to = v, p->nxt = adj[u], adj[u] = p;
		q->to = u, q->nxt = adj[v], adj[v] = q;
		p->rev = q, q->rev = p;
	}
	else {
		edge *p = (++ecnt);
		p->to = v, p->nxt = adj[u], adj[u] = p;
	}
}

int dfn[MAXM + 5], dcnt;
vector<pair<int, int> >ans;
int dfs(int x, edge *f) {
	int cnt = 0; dfn[x] = (++dcnt);
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p == f ) continue;
		if( !dfn[p->to] ) {
			if( dfs(p->to, p->rev))
				ans.push_back(make_pair(x, p->to));
			else ans.push_back(make_pair(p->to, x)), cnt ^= 1;
		}
		else if( dfn[p->to] <= dfn[x] )
			ans.push_back(make_pair(p->to, x)), cnt ^= 1;
	}
	return cnt;
}

int deg[MAXN + 5];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int a, b; scanf("%d%d", &a, &b);
		deg[a]++, deg[b]++, addedge(a, b);
	}
	int lst = 0;
	for(int i=1;i<=n;i++) {
		if( deg[i] & 1 ) {
			if( lst == 0 ) lst = i;
			else addedge(lst, i), lst = 0;
		}
	}
	if( dfs(1, NULL) ) ans.push_back(make_pair(1, 1));
	
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
}