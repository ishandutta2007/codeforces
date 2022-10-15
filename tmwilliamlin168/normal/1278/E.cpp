#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5;
int n, a0[2*mxN], pt, l[mxN], r[mxN];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	if(~p)
		adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	a0[pt-adj[u].size()]=u;
	for(int i=0; i<adj[u].size(); ++i) {
		a0[pt-adj[u].size()+1+i]=adj[u][i];
	}
	pt-=adj[u].size()+1;
	for(int i=0; i<adj[u].size(); ++i)
		dfs(adj[u][i], u);
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
	a0[2*n-1]=0;
	pt=2*n-2;
	dfs();
	for(int i=0; i<2*n; ++i) {
		if(l[a0[i]])
			r[a0[i]]=i+1;
		else
			l[a0[i]]=i+1;
	}
	for(int i=0; i<n; ++i)
		cout << l[i] << " " << r[i] << "\n";
}