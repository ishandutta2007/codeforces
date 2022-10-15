#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, k, ui, vi, d[mxN], qu[mxN], qt, nc[mxN], p[mxN];
vector<int> adj[mxN];

void fk() {
	cout << "NO";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i=0; i<n-1; ++i) {
		cin >> ui >> vi, --ui, --vi;
		adj[ui].push_back(vi);
		adj[vi].push_back(ui);
	}
	memset(d, 1, sizeof(d));
	for(int i=0; i<n; ++i) {
		if(adj[i].size()==1) {
			qu[qt++]=i;
			d[i]=0;
		}
	}
	memset(p, -1, sizeof(p));
	for(int qh=0; qh<n; ++qh) {
		int u=qu[qh];
		if(nc[u]<3&&d[u])
			fk();
		for(int v : adj[u]) {
			if(p[v]==u)
				continue;
			if(d[v]<1e7&&d[v]!=d[u]+1)
				fk();
			p[u]=v;
			if(d[v]>1e7)
				qu[qt++]=v;
			d[v]=d[u]+1;
			++nc[v];
		}
	}
	if(d[qu[n-1]]!=k)
		fk();
	cout << "Yes";
}