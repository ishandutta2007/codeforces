#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, q, x[mxN], y[mxN], ans=-1;
set<int> sx[mxN], sy[mxN];
bool vis[mxN];

void dfs(int u) {
	vis[u]=1;
	sx[x[u]].erase(u);
	sy[y[u]].erase(u);
	while(!sx[x[u]].empty())
		dfs(*sx[x[u]].begin());
	while(!sy[y[u]].empty())
		dfs(*sy[y[u]].begin());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> q;
	for(int i=0; i<q; ++i) {
		cin >> x[i] >> y[i], --x[i], --y[i];
		sx[x[i]].insert(i);
		sy[y[i]].insert(i);
	}
	for(int i=0; i<n; ++i)
		ans+=sx[i].empty();
	for(int i=0; i<m; ++i)
		ans+=sy[i].empty();
	for(int i=0; i<q; ++i) {
		if(!vis[i]) {
			dfs(i);
			++ans;
		}
	}
	cout << ans;	
}