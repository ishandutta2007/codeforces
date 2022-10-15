#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, s[mxN];
ll ans;
vector<int> adj[mxN];

void dfs1(int u=0, int p=-1) {
	s[u]=1;
	for(int v : adj[u]) {
		if(v^p) {
			dfs1(v, u);
			s[u]+=s[v];
		}
	}
}

void dfs2(ll ca, int u=0, int p=-1) {
	ans=max(ca, ans);
	for(int v : adj[u]) {
		if(v==p)
			continue;
		ca-=s[v];
		ca+=n-s[v];
		dfs2(ca, v, u);
		ca+=s[v];
		ca-=n-s[v];
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
	dfs1();
	ll ca=0;
	for(int i=0; i<n; ++i)
		ca+=s[i];
	dfs2(ca);
	cout << ans;
}