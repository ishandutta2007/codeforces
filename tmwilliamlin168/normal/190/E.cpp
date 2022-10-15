#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5;
int n, m, nxt[mxN+1];
vector<int> adj[mxN], grp;
vector<vector<int>> grps;
bool vis[mxN];

void dfs(int u) {
	vis[u]=1;
	grp.push_back(u);
	vector<int> tv;
	for(int i=0, i2=0; nxt[i]<=n; ) {
		while(i2<adj[u].size()&&adj[u][i2]<nxt[i]-1)
			++i2;
		if(i2>=adj[u].size()||adj[u][i2]!=nxt[i]-1) {
			tv.push_back(nxt[i]-1);
			nxt[i]=nxt[nxt[i]];
		} else
			i=nxt[i];
	}
	for(int v : tv)
		dfs(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<n; ++i)	
		sort(adj[i].begin(), adj[i].end());
	for(int i=0; i<=n; ++i)
		nxt[i]=i+1;
	while(nxt[0]<=n) {
		grp.clear();
		int u=nxt[0]-1;
		nxt[0]=nxt[nxt[0]];
		dfs(u);
		grps.push_back(grp);
	}
	cout << grps.size() << "\n";
	for(vector<int> &grp : grps) {
		cout << grp.size();
		for(int u : grp)
			cout << " " << u+1;
		cout << "\n";
	}
}