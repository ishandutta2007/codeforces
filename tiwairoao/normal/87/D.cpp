#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = int(1E5);
struct edge{
	int u, v, w, id;
	edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5];
bool operator < (edge a, edge b) {
	return a.w < b.w;
}
struct node{
	int id;
	long long key;
}ans[MAXN + 5];
bool operator < (node a, node b) {
	if( a.key == b.key ) return a.id < b.id;
	return a.key < b.key;
}
int N, fa[MAXN + 5], pre[MAXN + 5];
long long siz[MAXN + 5], dp[MAXN + 5];
int Find(int x) {
	if( x == fa[x] ) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	if( Find(x) != Find(y) ) {
		siz[Find(y)] += siz[Find(x)];
		fa[Find(x)] = Find(y);
	}
}
void dfs(int rt) {
	dp[rt] = siz[rt];
	for(edge *p=adj[rt];p!=NULL;p=p->nxt) {
		if( p->v == pre[rt] ) continue;
		pre[p->v] = rt; dfs(p->v);
		dp[rt] = dp[rt] + dp[p->v];
	}
}
vector<int>res;
int main() {
	scanf("%d", &N);
	for(int i=0;i<N-1;i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[2*i+1].u = edges[2*i].v = u;
		edges[2*i+1].v = edges[2*i].u = v;
		edges[2*i+1].w = edges[2*i].w = w;
		edges[2*i+1].id = edges[2*i].id = i+1;
		ans[i+1].id = i+1;
	}
	sort(edges, edges+2*N-2);
	for(int i=1;i<=N;i++)
		fa[i] = i, siz[i] = 1;
	int lst = 0;
	for(int i=0;i<2*N-2;i++) {
		if( edges[lst].w != edges[i].w ) {
			for(int j=i-1;j>=lst;j--)
				if( !dp[edges[j].u] ) {
					pre[edges[j].u] = -1;
					dfs(edges[j].u);
				}
			for(int j=i-1;j>=lst;j--)
				adj[edges[j].u] = adj[edges[j].v] = NULL;
			for(int j=i-1;j>=lst;j--)
				Union(edges[j].u, edges[j].v);
			for(int j=i-1;j>=lst;j--)
				if( pre[edges[j].u] == edges[j].v )
					ans[edges[j].id].key = (siz[Find(edges[j].u)] - dp[edges[j].u]) * dp[edges[j].u];
			for(int j=i-1;j>=lst;j--)
				dp[edges[j].u] = dp[edges[j].v] = pre[edges[j].u] = pre[edges[j].v] = 0;
			lst = i;
		}
		edges[i].u = Find(edges[i].u);
		edges[i].v = Find(edges[i].v);
		edges[i].nxt = adj[edges[i].u];
		adj[edges[i].u] = &edges[i];
	}
	for(int j=2*N-2-1;j>=lst;j--)
		if( !dp[edges[j].u] ) {
			pre[edges[j].u] = -1;
			dfs(edges[j].u);
		}
	for(int j=2*N-2-1;j>=lst;j--)
		adj[edges[j].u] = adj[edges[j].v] = NULL;
	for(int j=2*N-2-1;j>=lst;j--)
		Union(edges[j].u, edges[j].v);
	for(int j=2*N-2-1;j>=lst;j--)
		if( pre[edges[j].u] == edges[j].v )
			ans[edges[j].id].key = (siz[Find(edges[j].u)] - dp[edges[j].u]) * dp[edges[j].u];
	for(int j=2*N-2-1;j>=lst;j--) {
		dp[edges[j].u] = dp[edges[j].v] = 0;
		pre[edges[j].u] = pre[edges[j].v] = 0;
	}
	sort(ans+1, ans+N);
	for(int i=1;i<N;i++) {
		if( ans[N-1].key == ans[i].key )
			res.push_back(ans[i].id);
		//cout << ans[i].key << " " << ans[i].id << endl;
	}
	cout << ans[N-1].key * 2 << " " << res.size() << endl;
	int leng = res.size();
	cout << res[0];
	for(int i=1;i<leng;i++)
		cout << " " << res[i];
	cout << endl;
}/*
8
2 6 1
7 6 1
5 8 0
6 4 2
2 5 2
3 4 0
6 1 0
*/