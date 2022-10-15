#include <bits/stdc++.h>
using namespace std;

const int mxN=50, INF=0x69696969;

int n, s, m, dp1[mxN][mxN][mxN][mxN], dp2[mxN+1][mxN+1], adj[mxN][mxN], sz[mxN];
vector<int> children[mxN][mxN];

void dfs1(int u, int p) {
	for(int v=0; v<n; ++v) {
		if(adj[u][v]>=INF||v==p)
			continue;
		dfs1(v, u);
		sz[u]+=sz[v];
	}
}

int dp(int from, int to, int subCnt, int tCnt) {
	if(!tCnt)
		return 0;
	if(!subCnt)
		return INF;
	if(dp1[from][to][subCnt][tCnt]>=INF) {
		if(children[from][to].empty())
			dp1[from][to][subCnt][tCnt]=dp(to, from, tCnt-subCnt, tCnt-subCnt)+adj[from][to];
		else {
			for(int i=0; i<children[from][to].size(); ++i)
				for(int j=1; j<=subCnt; ++j)
					dp(to, children[from][to][i], j, tCnt);
			memset(dp2, 0, sizeof(dp2));
			dp2[0][0]=INF;
			for(int i=1; i<=children[from][to].size(); ++i)
				for(int j=0; j<=subCnt; ++j)
					for(int k=0; k<=j; ++k)
						dp2[i][j]=max(dp2[i][j], min(dp2[i-1][j-k], dp(to, children[from][to][i-1], k, tCnt)));
			dp1[from][to][subCnt][tCnt]=dp2[children[from][to].size()][subCnt]+adj[from][to];
		}
	}
	return dp1[from][to][subCnt][tCnt];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp1, 0x69, sizeof(dp1));
	memset(adj, 0x69, sizeof(adj));
	cin >> n;
	for(int i=0; i<n-1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u-1][v-1]=adj[v-1][u-1]=w;
	}
	cin >> s >> m;
	--s;
	for(int i=0; i<m; ++i) {
		int x;
		cin >> x;
		++sz[x-1];
	}
	dfs1(s, -1);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
				if(adj[i][j]<INF&&adj[i][k]<INF&&j!=k)
					children[j][i].push_back(k);
	int ans=INF;
	for(int i=0; i<n; ++i)
		if(adj[s][i]<INF)
			ans=min(dp(s, i, sz[i], m), ans);
	cout << ans;
}