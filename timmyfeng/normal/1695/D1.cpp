#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
set<int> adj[mxN];

void solve() {
	cin >> n;
	if (n==1) {
		cout << "0\n";
		return;
	}
	for (int i=0; i<n; ++i)
		adj[i].clear();
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	queue<int> q;
	for (int i=0; i<n; ++i)
		if (adj[i].size()==2)
			q.push(i);
	while(q.size()) {
		int u=q.front();
		q.pop();
		if (adj[u].size()!=2)
			continue;
		int a=*adj[u].begin(), b=*adj[u].rbegin();
		adj[a].erase(u);
		adj[b].erase(u);
		adj[a].insert(b);
		adj[b].insert(a);
		adj[u].clear();
		if (adj[a].size()==2)
			q.push(a);
		if (adj[b].size()==2)
			q.push(b);
	}
	int ans=0;
	for (int i=0; i<n; ++i) {
		int leaf=0;
		for (int j : adj[i])
			leaf+=adj[j].size()==1;
		ans+=max(0, leaf-1);
	}
	cout << max(1, ans) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}