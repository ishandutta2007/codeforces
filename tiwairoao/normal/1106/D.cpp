#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 100000 + 5;
struct edge{
	int to; edge *nxt;
}edges[2*MAXN], *adj[MAXN], *ecnt=&edges[0];
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
bool tag[MAXN];
priority_queue<int, vector<int>, greater<int> >que;
int main() {
	int n, m; scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	que.push(1); tag[1] = true;
	while( !que.empty() ) {
		int t = que.top(); que.pop();
		printf("%d ", t);
		for(edge *p=adj[t];p;p=p->nxt) {
			if( !tag[p->to] ) {
				que.push(p->to);
				tag[p->to] = true;
			}
		}
	}
}