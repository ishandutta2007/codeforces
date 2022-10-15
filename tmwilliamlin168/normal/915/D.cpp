#include <bits/stdc++.h>
using namespace std;

const int mxN=500;

int n, m, backEdges;
vector<int> graph1[mxN];
bool vis[mxN], act[mxN];

void dfs1(int u) {
	vis[u]=act[u]=1;
	for(int v : graph1[u]) {
		if(!vis[v])
			dfs1(v);
		else
			backEdges+=act[v];
		if(backEdges>1)
			return;
	}
	act[u]=0;
}

bool dfs2(int u) {
	vis[u]=act[u]=1;
	for(int v : graph1[u])
		if(!vis[v]&&dfs2(v)||act[v])
			return 1;
	act[u]=0;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph1[u].push_back(v);
	}
	for(int i=0; i<n; ++i) {
		memset(vis, 0, n);
		memset(act, 0, n);
		backEdges=0;
		dfs1(i);
		if(backEdges>1)
			continue;
		bool works=1;
		for(int j=0; j<n&&works; ++j)
			if(!vis[j])
				works&=!dfs2(j);
		if(works) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}