#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5, mxK=100;
int n, m, k, s, a[mxN], qu[mxN], qh, qt, dist[mxN], a2[mxN][mxK];
vector<int> adj[mxN], bt[mxK];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k >> s;
	for(int i=0; i<n; ++i)
		cin >> a[i], bt[--a[i]].push_back(i);
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0; i<k; ++i) {
		for(int j=0; j<n; ++j)
			a2[j][i]=mxN;
		qh=qt=0;
		for(int bti : bt[i])
			qu[qt++]=bti, a2[bti][i]=0;
		while(qh<qt) {
			int u=qu[qh++];
			for(int v : adj[u]) {
				if(a2[v][i]>=mxN) {
					qu[qt++]=v;
					a2[v][i]=a2[u][i]+1;
				}
			}
		}
	}
	for(int i=0; i<n; ++i) {
		nth_element(a2[i], a2[i]+s, a2[i]+k);
		int a3=0;
		for(int j=0; j<s; ++j)
			a3+=a2[i][j];
		cout << a3 << " ";
	}
}