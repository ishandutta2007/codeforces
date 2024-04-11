#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2000000;
struct edge{
	edge *nxt; int to;
}edges[MAXN + 5], *adj[MAXN + 5], *ecnt;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
}
int dfn[MAXN + 5], low[MAXN + 5], dcnt;
bool tag[MAXN + 5]; int stk[MAXN + 5], tp;
int bel[MAXN + 5], siz[MAXN + 5], tot;
void init(int n) {
	ecnt = edges, dcnt = tot = 0;
	for(int i=0;i<=n;i++)
		dfn[i] = 0, adj[i] = NULL, siz[i] = 0;
}
void dfs(int x) {
	dfn[x] = low[x] = (++dcnt);
	tag[stk[++tp] = x] = true;
	for(edge *p=adj[x];p;p=p->nxt) {
		if( dfn[p->to] ) {
			if( tag[p->to] )
				low[x] = min(low[x], dfn[p->to]);
		}
		else dfs(p->to), low[x] = min(low[x], low[p->to]);
	}
	if( low[x] >= dfn[x] ) {
		siz[++tot] = 0;
		do {
			int p = stk[tp];
			bel[p] = tot, siz[tot] += !(p & 1), tag[p] = false;
		}while( stk[tp--] != x );
	}
}
vector<int>v1, v2;
void solve() {
	int n, m; scanf("%d%d", &n, &m), init(n << 1);
	for(int i=1;i<=m;i++) {
		int a, b; scanf("%d%d", &a, &b), a--, b--;
		if( a == b ) continue;
		addedge(a << 1, b << 1);
		addedge(b << 1 | 1, a << 1 | 1);
	}
	for(int i=0;i<(n<<1);i++)
		if( !dfn[i] ) dfs(i);
	if( siz[1] != n ) {
		puts("Yes"), v1.clear(), v2.clear();
		for(int j=0;j<n;j++)
			if( bel[j<<1] == 1 ) v1.push_back(j + 1);
			else v2.push_back(j + 1);
		printf("%d %d\n", v1.size(), v2.size());
		for(int j=0;j<v1.size();j++) printf("%d ", v1[j]); puts("");
		for(int j=0;j<v2.size();j++) printf("%d ", v2[j]); puts("");
	}
	else puts("No");
}
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}