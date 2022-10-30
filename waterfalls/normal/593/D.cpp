#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,m;
vector<pair<pair<int,int>,ll> > edges;
vector<int> adj[200013];
int h[200013];
int up[200013];
ll val[200013];

int p[200013];
int find(int x) { return p[x]==x ? p[x] : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

void dfs(int x, int pp=0, int d=0) {
	h[x] = d;
	up[x] = pp;
	for (int i: adj[x]) if (i!=pp) dfs(i,x,d+1);
}

void update(int x, ll c) {
	val[x] = c;
	if (c==1) merge(x,up[x]);
}

void build() {
	for (auto e: edges) {
		adj[e.A.A].push_back(e.A.B);
		adj[e.A.B].push_back(e.A.A);
	}
	dfs(1);
	for (int i=1;i<=n;i++) {
		val[i] = 2e18;
		p[i] = i;
	}
	for (auto e: edges) {
		int x = (h[e.A.A]>h[e.A.B]) ? e.A.A : e.A.B;
		update(x,e.B);
	}
}

ll go(int a, int b, ll y) {
	while (a!=b) {
		if (h[a]<h[b]) swap(a,b);
		y/=val[a];
		if (y==0) return y;
		a = find(up[a]);
	}
	return y;
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		int u,v;
		ll x;
		scanf("%d%d%lld",&u,&v,&x);
		edges.push_back(MP(MP(u,v),x));
	}
	build();
	for (int q=0;q<m;q++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int a,b;
			ll y;
			scanf("%d%d%lld",&a,&b,&y);
			y = go(a,b,y);
			printf("%lld\n",y);
		} else {
			int x;
			ll c;
			scanf("%d%lld",&x,&c);
			auto e = edges[x-1];
			x = (h[e.A.A]>h[e.A.B]) ? e.A.A : e.A.B;
			update(x,c);
		}
	}

	return 0;
}