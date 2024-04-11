#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;
struct Edge {
	int a,b,c,i;
	bool operator<(Edge o) const { return c<o.c; }
};

int p[200013];
int find(int x) { return p[x]==x ? x : p[x] = find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n,m;
vector<pair<int,int> > adj[200013];
int h[200013];
int up[18][200013];
int high[18][200013];

vector<Edge> edges;
ll ans[200013];

int path(int a, int b) {
	int res = 0;
	if (h[a]>h[b]) swap(a,b);
	for (int i=17;i>=0;i--) if ((h[b]-h[a])&(1<<i)) {
		res = max(res,high[i][b]);
		b = up[i][b];
	}
	if (a==b) return res;
	for (int i=17;i>=0;i--) if (up[i][a]!=up[i][b]) {
		res = max(res,max(high[i][a],high[i][b]));
		a = up[i][a]; b = up[i][b];
	}
	return max(res,max(high[0][a],high[0][b]));
}

void dfs(int x, int pp=0, int d=0, int above=0) {
	h[x] = d;
	up[0][x] = pp;
	high[0][x] = above;
	for (auto i: adj[x]) if (i.A!=pp) dfs(i.A,x,d+1,i.B);
}

int main() {
	scanf("%d%d",&n,&m);
	edges.resize(m);
	for (int i=0;i<m;i++) {
		scanf("%d%d%d",&edges[i].a,&edges[i].b,&edges[i].c);
		edges[i].i = i+1;
	}
	sort(edges.begin(),edges.end());
	iota(p,p+n+1,0);
	ll cur = 0;
	for (Edge e: edges) {
		if (find(e.a)!=find(e.b)) {
			adj[e.a].push_back(MP(e.b,e.c));
			adj[e.b].push_back(MP(e.a,e.c));
			merge(e.a,e.b);
			cur+=e.c;
		}
	}
	dfs(1);
	for (int i=1;i<18;i++) for (int j=1;j<=n;j++) {
		up[i][j] = up[i-1][up[i-1][j]];
		high[i][j] = max(high[i-1][j],high[i-1][up[i-1][j]]);
	}
	for (Edge e: edges) ans[e.i] = cur+e.c-path(e.a,e.b);
	for (int i=1;i<=m;i++) printf("%lld\n",ans[i]);

	return 0;
}