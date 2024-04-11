#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second

int p[500013];
int find(int x) { return p[x]==x ? x : p[x]=find(p[x]); }
void merge(int a, int b) { p[find(a)] = find(b); }

int n;
int a[500013], b[500013], c[500013], d[500013];
set<pair<int,int> > one, two;
vector<pair<int,int> > adj[500013];
pair<int,int> fa[500013];

void setup(int x, pair<int,int> pp=MP(0,0)) {
	fa[x] = pp;
	for (auto i: adj[x]) {
		if (i.A!=pp.B) setup(find(i.A),i);
	}
}

void dfs(int x, pair<int,int> pp=MP(0,0)) {
	for (auto i: adj[x]) {
		if (i.A!=pp.B) dfs(find(i.A),i);
	}
	if (x==find(1)) return;
	printf("%d %d %d %d\n",pp.B,pp.A,fa[x].B,fa[x].A);
}

int main() {
	scanf("%d",&n);
	iota(p,p+n+1,0);
	for (int i=1;i<n;i++) {
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]>b[i]) swap(a[i],b[i]);
		one.insert(MP(a[i],b[i]));
	}
	for (int i=1;i<n;i++) {
		scanf("%d%d",&c[i],&d[i]);
		if (c[i]>d[i]) swap(c[i],d[i]);
		auto it = one.find(MP(c[i],d[i]));
		if (it!=one.end()) {
			one.erase(it);
			merge(c[i],d[i]);
		} else two.insert(MP(c[i],d[i]));
	}
	for (auto p: two) {
		adj[find(p.A)].push_back(MP(p.B,p.A));
		adj[find(p.B)].push_back(MP(p.A,p.B));
	}
	setup(find(1));
	for (int i=1;i<=n;i++) adj[i].clear();
	for (auto p: one) {
		adj[find(p.A)].push_back(MP(p.B,p.A));
		adj[find(p.B)].push_back(MP(p.A,p.B));
	}
	printf("%d\n",one.size());
	dfs(find(1));

	return 0;
}