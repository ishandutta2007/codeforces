#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, a[mxN], qt=1;
set<int> adj[mxN];
bool vis[mxN];

void fk() {
	cout << "No";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n-1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i=0; i<n; ++i)
		cin >> a[i], --a[i];
	if(a[0])
		fk();
	vis[0]=1;
	for(int qh=0; qh<qt; ++qh) {
		while(qt<n&&adj[a[qh]].find(a[qt])!=adj[a[qh]].end())
			++qt;
	}
	if(qt<n)
		fk();
	cout << "Yes";
}