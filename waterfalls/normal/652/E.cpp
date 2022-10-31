#include <bits/stdc++.h>
using namespace std;

pair<int,int> MP(int a, int b) { return make_pair(min(a,b),max(a,b)); }
#define A first
#define B second

int p[300013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n,m,a,b;
set<int> adj[300013];
set<pair<int,int> > bridges;
set<pair<int,int> > art;
int h[300013], up[300013];
bool has[300013], mark[300013];

int counter = 0;
int num[300013], low[300013];
void setup(int x, int pp=0) {
	num[x] = low[x] = ++counter;
	for (int i: adj[x]) {
		if (!num[i]) {
			setup(i,x);
			low[x] = min(low[x],low[i]);
			if (low[i]>num[x]) {
				bridges.insert(MP(i,x));
			}
		} else if (i!=pp) low[x] = min(low[x],num[i]);
		else pp = 0;
	}
}

void setup2(int x, int pp=0, int d=0) {
	h[x] = d;
	up[x] = pp;
	for (int i: adj[x]) if (i!=pp) {
		setup2(i,x,d+1);
	}
}

void edgebcc() {
	setup(1);
	for (auto p: bridges) {
		adj[p.A].erase(p.B);
		adj[p.B].erase(p.A);
	}
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++) {
		for (int j: adj[i]) merge(j,i);
		adj[i].clear();
	}
	for (auto p: bridges) {
		adj[find(p.A)].insert(find(p.B));
		adj[find(p.B)].insert(find(p.A));
	}
	setup2(find(1));
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		adj[x].insert(y);
		adj[y].insert(x);
		if (z) art.insert(MP(x,y));
	}
	edgebcc();
	for (auto p: art) {
		if (!bridges.count(p)) {
			has[find(p.A)] = 1;
		} else {
			if (h[find(p.A)]<h[find(p.B)]) swap(p.A,p.B);
			mark[find(p.A)] = 1;
		}
	}
	scanf("%d%d",&a,&b);
	a = find(a); b = find(b);
	while (a!=b) {
		if (h[a]<h[b]) swap(a,b);
		if (has[a] || mark[a]) return printf("YES\n"), 0;
		a = up[a];
	}
	if (has[a]) return printf("YES\n"), 0;
	printf("NO\n");

	return 0;
}