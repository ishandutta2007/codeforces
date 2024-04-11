#include<set>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define illegal {puts("-1"); exit(0);}
const int MAXK = 200;
const int MAXN = 30000;
struct edge{
	int to; edge *nxt;
}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt = &edges[0];
set<pair<int, int> >st;
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void addedge(int u, int v) {
	if( st.count(make_pair(min(u, v), max(u, v))) )
		return ;
	if( find(u) == find(v) )
		illegal;
	st.insert(make_pair(min(u, v), max(u, v)));
	fa[find(u)] = find(v);
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
	p = (++ecnt);
	p->to = u, p->nxt = adj[v], adj[v] = p;
}
int dep[MAXN + 5], stp[20][MAXN + 5];
void dfs1(int x, int f, bool flag) {
	dep[x] = dep[f] + 1, stp[0][x] = f;
	if( flag ) {
		for(int i=1;i<20;i++)
			stp[i][x] = stp[i-1][stp[i-1][x]];
	}
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		dfs1(p->to, x, flag);
	}
}
void print(int x, int f) {
	for(edge *p=adj[x];p;p=p->nxt) {
		if( p->to == f ) continue;
		printf("%d %d\n", x, p->to);
		print(p->to, x);
	}
}
int kth(int x, int d) {
	for(int i=19;i>=0;i--)
		if( dep[stp[i][x]] >= d )
			x = stp[i][x];
	return x;
}
vector<pair<int, int> >v[MAXN + 5];
int d[MAXK + 5][MAXN + 5], n, k;
int pos[MAXK + 5], tag[MAXN + 5], rt;
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++)
		fa[i] = i;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &d[i][j]);
	for(int i=1;i<=k;i++) {
		pos[i] = -1;
		for(int j=1;j<=n;j++)
			if( d[i][j] == 0 ) {
				if( pos[i] == -1 ) pos[i] = j;
				else illegal
			}
		if( pos[i] == -1 )
			illegal
	}
	rt = pos[1];
	for(int i=1;i<=k;i++) {
		int dis = d[1][pos[i]];
		for(int j=0;j<=dis;j++)
			tag[j] = -1;
		for(int j=1;j<=n;j++)
			if( d[i][j] + d[1][j] == dis ) {
				if( tag[d[i][j]] == -1 )
					tag[d[i][j]] = j;
				else illegal
			}
			else if( d[i][j] + d[1][j] < dis )
				illegal
		for(int j=0;j<=dis;j++)
			if( tag[j] == -1 ) illegal
		for(int j=0;j<dis;j++)
			addedge(tag[j], tag[j + 1]);
	}
	for(int i=0;i<=n;i++) dep[i] = -1;
	dfs1(rt, 0, true);
	for(int i=1;i<=n;i++) {
		if( dep[i] != -1 ) continue;
		int p = 1, q = 0;
		for(int j=1;j<=k;j++) {
			int k = dep[pos[j]] + d[1][i] - d[j][i];
			if( k & 1 ) illegal
			else k >>= 1;
			if( k > q )
				q = k, p = j;
		}
		v[kth(pos[p], q)].push_back(make_pair(d[1][i], i));
	}
	for(int i=1;i<=n;i++) {
		if( dep[i] == -1 ) continue;
		int mx = 0;
		for(int j=0;j<v[i].size();j++)
			mx = max(mx, v[i][j].first - dep[i]);
		for(int j=0;j<=mx;j++)
			tag[j] = -1;
		tag[0] = i;
		for(int j=0;j<v[i].size();j++)
			tag[v[i][j].first - dep[i]] = v[i][j].second;
		for(int j=0;j<=mx;j++)
			if( tag[j] == -1 ) illegal
		for(int j=0;j<v[i].size();j++)
			addedge(tag[v[i][j].first - dep[i] - 1], v[i][j].second);
	}
	for(int i=1;i<=k;i++) {
		dfs1(pos[i], 0, false);
		for(int j=1;j<=n;j++)
			if( d[i][j] != dep[j] ) illegal
	}
	print(rt, 0);
}