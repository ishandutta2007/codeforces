#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, h[mxN], ans1, ans2[mxN];
vector<int> adj[mxN], a[mxN];

void mrg(int u, int v) {
	if(a[u].size()<a[v].size())
		swap(a[u], a[v]);
	a[u].insert(a[u].end(), a[v].begin(), a[v].end());
	a[v].clear();
}

void dfs(int u=0, int p=-1) {
	a[u]={u};
	if(u) {
		for(int v : adj[u]) {
			if(v==p)
				continue;
			dfs(v, u);
			if(h[v])
				++ans1;
			else {
				mrg(u, v);
				h[u]=1;
			}
		}
	} else {
		set<int> s;
		for(int v : adj[u]) {
			dfs(v, u);
			if(!h[v])
				s.insert(v);
		}
		if(s.empty())
			s.insert(adj[u][0]);
		for(int v : adj[u]) {
			if(s.find(v)==s.end())
				++ans1;
			else
				mrg(u, v);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1, a, b; i<n; ++i) {
		cin >> a >> b, --a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs();
	cout << 2*(n-1-ans1) << "\n";
	for(int i=0; i<n; ++i) {
		if(!a[i].size())
			continue;
		for(int j=0; j<a[i].size(); ++j)
			ans2[a[i][j]]=a[i][(j+1)%a[i].size()];
	}
	for(int i=0; i<n; ++i)
		cout << ans2[i]+1 << " ";
}