#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define repG(G, x) for(Graph::edge *p = G.adj[x];p;p = p->nxt)
#define repS(S) for(set<int>::iterator it = S.begin();it != S.end();it++)
#define fi first
#define se second
#define mp make_pair
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int MAXN = 1000;
const int MAXM = 12;
const int MAXK = (1<<MAXM);
const int MOD = int(1E9) + 7;
struct Graph{
	struct edge{
		int to; edge *nxt;
	}edges[2*MAXN + 5], *adj[MAXN + 5], *ecnt;
	Graph() {ecnt = edges;}
	void addedge(int u, int v) {
		edge *p = (++ecnt);
		p->to = v, p->nxt = adj[u], adj[u] = p;
		p = (++ecnt);
		p->to = u, p->nxt = adj[v], adj[v] = p;
	}
}S, T;
map<ull, int>m1; int hcnt;
int id(ull x) {
	if( m1.count(x) ) return m1[x];
	else return m1[x] = (++hcnt);
}
ull r[MAXM + 5], h[MAXM + 5]; int s[MAXM + 5];
set<int>st2[MAXK + 5];
vector<pii>trans[MAXK + 5];
vector<int>a;
void dfs1(int x, int fa) {
	s[x] = h[x] = 1;
	repG(T, x) {
		if( p->to == fa ) continue;
		dfs1(p->to, x), h[x] += r[s[p->to]] * h[p->to], s[x] += s[p->to];
	}
	a.clear();
	repG(T, x) {
		if( p->to == fa ) continue;
		a.push_back(p->to);
	}
	int k = a.size(), t = (1<<k);
	for(int s1=0;s1<t;s1++) {
		ull hsh = 1;
		for(int p=0;p<k;p++)
			if( (s1 >> p) & 1 )
				hsh += r[s[a[p]]] * h[a[p]];
		int x = id(hsh);
		for(int p=0;p<k;p++)
			if( !((s1 >> p) & 1) ) {
				int y = id(h[a[p]]);
				if( !st2[x].count(y) ) {
					st2[x].insert(y);
					trans[x].push_back(mp(y, id(hsh + r[s[a[p]]] * h[a[p]])));
				}
			}
	}
}
int f[MAXN + 5][MAXK + 5], g[MAXK + 5];
void dfs2(int x, int fa) {
	f[x][1] = 1;
	repG(S, x) {
		if( p->to == fa ) continue;
		dfs2(p->to, x);
		for(int i=1;i<=hcnt;i++)
			g[i] = f[x][i];
		for(int i=1;i<=hcnt;i++)
			if( g[i] ) {
				for(int j=0;j<trans[i].size();j++) {
					int p1 = trans[i][j].fi, q1 = trans[i][j].se;
					f[x][q1] = (f[x][q1] + 1LL*g[i]*f[p->to][p1]%MOD)%MOD;
				}
			}
	}
}
set<int>st; int NS, NT;
void get_rand() {
	srand(20041112^NS^NT);
	for(int i=1;i<=NT;i++)
		r[i] = ((ull(rand()) << 16 | rand()) << 16 | rand()) << 16 | rand();
}
int main() {
	scanf("%d", &NS);
	for(int i=1;i<NS;i++) {
		int u, v; scanf("%d%d", &u, &v);
		S.addedge(u, v);
	}
	scanf("%d", &NT);
	for(int i=1;i<NT;i++) {
		int u, v; scanf("%d%d", &u, &v);
		T.addedge(u, v);
	}
	get_rand();
	for(int i=1;i<=NT;i++)
		dfs1(i, 0), st.insert(id(h[i]));
	int ans = 0; dfs2(1, 0);
	for(int i=1;i<=NS;i++)
		repS(st) ans = (ans + f[i][*it]) % MOD;
	printf("%d\n", ans);
}