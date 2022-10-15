#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, s[mxN], dt, ds[mxN], ord[mxN];
vector<int> adj[mxN];
long long ans1;

void dfs(int u=0, int p=-1) {
	ord[u]=dt;
	ds[dt++]=u;
	s[u]=1;
	for(int v : adj[u]) {
		if(v==p)
			continue;
		dfs(v, u);
		ans1+=min(s[v], n-s[v]);
		s[u]+=s[v];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << 2*ans1 << "\n";
	for(int i=0; i<n; ++i)
		cout << ds[(ord[i]+n/2)%n]+1 << " ";
}