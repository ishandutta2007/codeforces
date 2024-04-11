#include <bits/stdc++.h>
using namespace std;

const int mxN=3000, mxlgN=11, mxQ=400000;

int n, m, q, lgn, dist[mxN], nxt[mxlgN+2][mxN], qS[mxQ], qT[mxQ], qK[mxQ], ans[mxQ];
vector<int> graph[mxN], graphRev[mxN], queriesByDest[mxN];

void dfs1(int u, int p) {
	dist[u]=p==-1?0:dist[p]+1;
	for(int v : graphRev[u])
		if(v!=p&&dist[v]==-1)
			dfs1(v, u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	lgn=31-__builtin_clz(n);;
	for(int i=0; i<m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graphRev[v].push_back(u);
	}
	for(int i=0; i<n; ++i)
		sort(graph[i].begin(), graph[i].end());
	for(int i=0; i<q; ++i) {
		cin >> qS[i] >> qT[i] >> qK[i];
		--qS[i], --qT[i], --qK[i];
		queriesByDest[qT[i]].push_back(i);
	}
	for(int t=0; t<n; ++t) {
		memset(dist, -1, sizeof(dist));
		dfs1(t, -1);
		for(int i=0; i<n; ++i) {
			nxt[0][i]=i;
			for(int j : graph[i]) {
				if(dist[j]!=-1) {
					nxt[0][i]=j;
					break;
				}
			}
		}
		nxt[0][t]=t;
		for(int i=1; i<=lgn+1; ++i)
			for(int j=0; j<n; ++j)
				nxt[i][j]=nxt[i-1][nxt[i-1][j]];
		for(int qi : queriesByDest[t]) {
			if(nxt[lgn+1][qS[qi]]!=t) {
				ans[qi]=-1;
				continue;
			}
			if(!qK[qi]) {
				ans[qi]=qS[qi]+1;
				continue;
			}
			for(int i=lgn+1; i>=0; --i) {
				if(1<<i<=qK[qi]-1) {
					qK[qi]-=1<<i;
					qS[qi]=nxt[i][qS[qi]];
				}
			}
			ans[qi]=qS[qi]==t?-1:nxt[0][qS[qi]]+1;
		}
	}
	for(int i=0; i<q; ++i)
		cout << ans[i] << "\n";
}