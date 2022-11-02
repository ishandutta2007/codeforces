#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 200000;
struct edge{
	edge *nxt; int to;
}edges[MAXN + 5], *adj[MAXN + 5], *ecnt = edges;
void addedge(int u, int v) {
	edge *p = (++ecnt);
	p->to = v, p->nxt = adj[u], adj[u] = p;
}
bool tag[MAXN + 5];
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
bool unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx == fy ) return false;
	else {
		fa[fx] = fy;
		return true;
	}
}
vector<int>cir[MAXN + 5]; int cnt;
bool dfs1(int x, const int &y) {
	if( x == y ) {
		tag[x] = true, cir[cnt].push_back(x);
		return true;
	}
	for(edge *p=adj[x];p;p=p->nxt)
		if( dfs1(p->to, y) ) {
			tag[x] = true, cir[cnt].push_back(x);
			return true;
		}
	return false;
}
struct query{
	int type, id; ll m;
	query(int _t=0, int _i=0, ll _m=0) : type(_t), id(_i), m(_m) {}
	friend bool operator < (query a, query b) {
		return (a.m == b.m ? a.type > b.type : a.m > b.m);
	}
};
int ans[MAXN + 5];
vector<query>qry[MAXN + 5];
int tot[MAXN + 5], mxdep, s;
priority_queue<query>que;
int nxt(int x) {return x == s - 1 ? 0 : x + 1;}
void dfs2(int x, int dep, const int &id, int ps) {
	que.push(query(-1, cir[id][ps], dep));
	mxdep = max(mxdep, dep);
	if( !tag[x] ) {
		for(int i=0;i<qry[x].size();i++)
			if( dep + qry[x][i].m <= MAXN )
				ans[qry[x][i].id] -= tot[dep + qry[x][i].m];
	}
	tot[dep]++;
	for(edge *p=adj[x];p;p=p->nxt)
		if( !tag[p->to] ) dfs2(p->to, dep + 1, id, nxt(ps));
	if( !tag[x] ) {
		for(int i=0;i<qry[x].size();i++)
			if( dep + qry[x][i].m <= MAXN )
				ans[qry[x][i].id] += tot[dep + qry[x][i].m];
	}
}
int res[MAXN + 5];
int main() {
	int N, M; scanf("%d", &N);
	for(int i=1;i<=N;i++) fa[i] = i;
	for(int i=1;i<=N;i++) {
		int x; scanf("%d", &x);
		if( !unite(x, i) )
			cnt++, dfs1(i, x), reverse(cir[cnt].begin(), cir[cnt].end());
		addedge(x, i);
	}
/*
	for(int i=1;i<=cnt;i++) {
		for(int j=0;j<cir[i].size();j++)
			printf("%d ", cir[i][j]);
		puts("");
	}
*/
	scanf("%d", &M);
	for(int i=1;i<=M;i++) {
		ll m; int y; scanf("%lld%d", &m, &y);
		qry[y].push_back(query(0, i, m));
	}
	for(int i=1;i<=cnt;i++) {
		s = (int)cir[i].size();
		for(int j=0;j<s;j++) {
			int x = cir[i][j];
			mxdep = 0, dfs2(x, 0, i, j);
			for(int k=0;k<=mxdep;k++) tot[k] = 0;
			for(int k=0;k<qry[x].size();k++) {
				int y = cir[i][(j + qry[x][k].m)%s];
				que.push(query(qry[x][k].id, y, qry[x][k].m));
			}
		}
		while( !que.empty() ) {
			query t = que.top(); que.pop();
			if( t.type == -1 )
				res[t.id]++;
			else ans[t.type] = res[t.id];
		}
	}
	for(int i=1;i<=M;i++)
		printf("%d\n", ans[i]);
}