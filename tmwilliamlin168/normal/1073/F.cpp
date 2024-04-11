#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=2e5;
int n, ui, vi, rt, p[mxN], a1=-1, a2=-1, c[mxN];
vector<int> adj[mxN];
bool r[mxN], vis[mxN];
vector<array<int, 2>> e[mxN];
ll d[mxN];

void dfs(int u, int pu) {
	vis[u]=1;
	p[u]=pu;
	d[u]=pu==-1?0:d[pu]+n;
	for(int v : adj[u])
		if(!vis[v])
			dfs(v, u);
	d[u]+=c[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n-1; ++i) {
		cin >> ui >> vi, --ui, --vi;
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}
	for(int i=0; i<n; ++i) {
		if(adj[i].size()>1)
			continue;
		int j=i, a=0;
		while(adj[j].size()<3) {
			r[j]=1;
			++a;
			j=adj[j][r[adj[j][0]]];
		}
		e[j].push_back({a, i});
		rt=j;
	}
	for(int i=0; i<n; ++i) {
		if(e[i].size()<2)
			continue;
		sort(e[i].begin(), e[i].end(), greater<array<int, 2>>());
		c[i]=e[i][0][0]+e[i][1][0];
	}
	memcpy(vis, r, n);
	dfs(rt, -1);
	for(int i=0; i<n; ++i)
		if(d[i]>d[rt])
			rt=i;
	memcpy(vis, r, n);
	dfs(rt, -1);
	int de=rt;
	for(int i=0; i<n; ++i)
		if(d[i]>d[de])
			de=i;
	for(int i=0; i<2; ++i)
		cout << e[rt][i][1]+1 << " " << e[de][i][1]+1 << "\n";
}