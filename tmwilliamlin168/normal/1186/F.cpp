#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, m, eu[mxN], ev[mxN], nxt[mxN];
set<int> adj[mxN];
vector<int> ans;
bool a[mxN];

void dfs(int u, int pe=-1, int d=0) {
	if(~pe) {
		if(d)
			ans.push_back(pe);
		adj[u].erase(pe);
		if(!adj[u].size()) {
			if(!d)
				ans.push_back(pe);
			return;
		}
	}
	int e=*adj[u].begin();
	adj[u].erase(e);
	dfs(eu[e]^ev[e]^u, e, d^1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i], --eu[i], --ev[i];
		adj[eu[i]].insert(i);
		adj[ev[i]].insert(i);
	}
	for(int i=0; i<n; ++i)
		if(adj[i].size()&1)
			dfs(i);
	for(int i=0; i<n; ++i)
		if(adj[i].size())
			dfs(i);
	cout << ans.size() << "\n";
	for(int e : ans)
		cout << eu[e]+1 << " " << ev[e]+1 << "\n";
}