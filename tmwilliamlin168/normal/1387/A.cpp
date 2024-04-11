#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5, A=1e9;
int n, m, c[mxN], eu[mxN], ev[mxN], ew[mxN], d2[mxN];
vector<int> adj[mxN], ve;
bool vis1[mxN], vis2[mxN], d1[mxN];

void fk() {
	cout << "NO";
	exit(0);
}

void dfs1(int u, int x) {
	vis1[u]=1;
	c[u]=x;
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(vis1[v]) {
			if(c[u]+c[v]!=2*ew[e])
				fk();
		} else
			dfs1(v, 2*ew[e]-x);
	}
}

int dfs2(int u) {
	vis2[u]=1;
	ve.push_back(d1[u]?d2[u]:-d2[u]);
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(!vis2[v]) {
			d1[v]=!d1[u];
			d2[v]=2*ew[e]-d2[u];
			int x=dfs2(v);
			if(x<A)
				return x;
		} else {
			if(d1[u]^d1[v]) {
				if(2*ew[e]-d2[u]!=d2[v])
					fk();
			} else
				return (ew[e]-(d2[u]+d2[v])/2)*(d1[u]?-1:1);
		}
	}
	return A;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	for(int i=0; i<n; ++i) {
		if(vis1[i])
			continue;
		int x=dfs2(i);
		if(x==A) {
			sort(ve.begin(), ve.end());
			x=ve[ve.size()/2];
		}
		dfs1(i, x);
		ve.clear();
	}
	cout << "YES\n";
	for(int i=0; i<n; ++i)
		cout << c[i]/2.0 << " ";
}