#include<cstdio>
const int MAXN = 200000;
struct edge{
	int to;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt=&edges[0];
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
long long dp[2][MAXN + 5], ans, siz[2][MAXN + 5];
void dfs(int rt, int pre) {
	siz[0][rt] = 1;
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->to == pre ) continue;
		dfs(p->to, rt);
		ans += (siz[0][rt]*siz[1][p->to] + dp[0][rt]*siz[1][p->to] + dp[1][p->to]*siz[0][rt])/2;
		ans += (siz[1][rt]*siz[0][p->to] + dp[1][rt]*siz[0][p->to] + dp[0][p->to]*siz[1][rt])/2;
		ans += (2*siz[1][rt]*siz[1][p->to] + siz[1][rt]*dp[1][p->to] + siz[1][p->to]*dp[1][rt])/2;
		ans += (2*siz[0][rt]*siz[0][p->to] + siz[0][rt]*dp[0][p->to] + siz[0][p->to]*dp[0][rt])/2;
		siz[0][rt] += siz[1][p->to];
		siz[1][rt] += siz[0][p->to];
		dp[0][rt] += dp[1][p->to] + siz[1][p->to];
		dp[1][rt] += dp[0][p->to] + siz[0][p->to];
	}
}
int main() {
	int N;
	scanf("%d", &N);
	for(int i=1;i<N;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, -1);
	printf("%I64d\n", ans);
}