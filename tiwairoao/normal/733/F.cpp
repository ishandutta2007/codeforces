#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
const ll INF = (1ll << 62);
struct edge{
	int u, v, id;
	ll w, c; bool f;
}edges[MAXN + 5];
bool operator < (edge a, edge b) {
	return a.w < b.w;
}
int n, m, mx; ll sum, S;
int fa[MAXN + 5];
int Find(int x) {
	if( fa[x] == x ) return x;
	else return fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
	if( Find(x) != Find(y) )
		fa[Find(x)] = Find(y);
}
vector<pair<int, int> >G[MAXN + 5];
void addedge(int u, int v, int w) {
	G[u].push_back(make_pair(v, w));
	G[v].push_back(make_pair(u, w));
}
void Kruscal() {
	mx = 1;
	sort(edges+1, edges+m+1);
	for(int i=1;i<=n;i++)
		fa[i] = i;
	for(int i=1;i<=m;i++) {
		if( Find(edges[i].u) != Find(edges[i].v) ) {
			Union(edges[i].u, edges[i].v);
			addedge(edges[i].u, edges[i].v, i);
			sum += edges[i].w, edges[i].f = true;
			if( S/edges[i].c > S/edges[mx].c )
				mx = i;
		}
	}
}
int Pre[MAXN + 5][20], dep[MAXN + 5];
int Max[MAXN + 5][20];
void dfs(int rt, int f, int w) {
	Pre[rt][0] = f, Max[rt][0] = w;
	for(int i=1;i<20;i++) {
		Pre[rt][i] = Pre[Pre[rt][i-1]][i-1];
		if( edges[Max[rt][i-1]].w > edges[Max[Pre[rt][i-1]][i-1]].w )
			Max[rt][i] = Max[rt][i-1];
		else Max[rt][i] = Max[Pre[rt][i-1]][i-1];
	}
	dep[rt] = dep[Pre[rt][0]] + 1;
	for(int i=0;i<(int)G[rt].size();i++) {
		if( G[rt][i].first != f )
			dfs(G[rt][i].first, rt, G[rt][i].second);
	}
}
int LCA(int u, int v) {
	if( dep[u] < dep[v] )
		swap(u, v);
	int ret = 0;
	for(int i=19;i>=0;i--) {
		if( dep[Pre[u][i]] >= dep[v] ) {
			if( edges[ret].w < edges[Max[u][i]].w )
				ret = Max[u][i];
			u = Pre[u][i];
		}
	}
	if( u == v )
		return ret;
	for(int i=19;i>=0;i--)
		if( Pre[u][i] != Pre[v][i] ) {
			if( edges[ret].w < edges[Max[u][i]].w )
				ret = Max[u][i];
			if( edges[ret].w < edges[Max[v][i]].w )
				ret = Max[v][i];
			u = Pre[u][i], v = Pre[v][i];
		}
	if( edges[ret].w < edges[Max[u][0]].w )
		ret = Max[u][0];
	if( edges[ret].w < edges[Max[v][0]].w )
		ret = Max[v][0];
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++)
		scanf("%I64d", &edges[i].w);
	for(int i=1;i<=m;i++)
		scanf("%I64d", &edges[i].c);
	for(int i=1;i<=m;i++)
		scanf("%d%d", &edges[i].u, &edges[i].v);
	for(int i=1;i<=m;i++)
		edges[i].id = i;
	scanf("%I64d", &S);
	edges[0].w = -INF;
	Kruscal(); dfs(1, 0, 0);
	ll ans = sum - S/edges[mx].c;
	int ansx = -1, ansy = -1;
	for(int i=1;i<=m;i++) {
		if( !edges[i].f ) {
			int p = LCA(edges[i].u, edges[i].v);
			if( sum - edges[p].w + edges[i].w - S/edges[i].c < ans ) {
				ansx = i, ansy = p;
				ans = sum - edges[p].w + edges[i].w - S/edges[i].c;
			}
		}
	}
	printf("%I64d\n", ans);
	for(int i=1;i<=m;i++) {
		if( edges[i].f ) {
			if( i == ansy ) {
				printf("%d %I64d", edges[ansx].id, edges[ansx].w - S/edges[ansx].c);
			}
			else {
				printf("%d ", edges[i].id);
				if( ansx == -1 && i == mx )
					printf("%I64d", edges[i].w - S/edges[i].c);
				else printf("%I64d", edges[i].w);
			}
			puts("");
		}
	}
}