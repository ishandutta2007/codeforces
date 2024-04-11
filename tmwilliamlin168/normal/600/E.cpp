#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, c[mxN];
vector<int> adj[mxN];
ll ans[mxN];

struct d {
	int a=1;
	map<int, int> c;
	map<int, ll> s;
} ds[mxN];

void mrg(d &a, d &b) {
	a.a+=b.a;
	for(auto p : b.c) {
		int c2=p.first;
		a.s[a.c[c2]]-=c2+1;
		a.c[c2]+=p.second;
		a.s[a.c[c2]]+=c2+1;
	}
}

void dfs(int u=0, int p=-1) {
	ds[u].c[c[u]]=1;
	ds[u].s[1]=c[u]+1;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
		if(ds[v].a>ds[u].a) {
			swap(ds[u].a, ds[v].a);
			swap(ds[u].c, ds[v].c);
			swap(ds[u].s, ds[v].s);
		}
		mrg(ds[u], ds[v]);
	}
	ans[u]=(--ds[u].s.end())->second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> c[i], --c[i];
	for(int i=1, x, y; i<n; ++i) {
		cin >> x >> y, --x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs();
	for(int i=0; i<n; ++i)
		cout << ans[i] << " ";
}