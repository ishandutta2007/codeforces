#include <bits/stdc++.h>
using namespace std;

inline void fk() {
	cout << -1;
	exit(0);
}

const int mxN=3e5;
vector<int> graph[mxN];
bool vis[mxN], act[mxN];
int dp[mxN][26], ans;
string s;

void dfs1(int u) {
	vis[u]=act[u]=1;
	for(int v : graph[u]) {
		if(act[v])
			fk();
		if(!vis[v])
			dfs1(v);
		for(int i=0; i<26; ++i)
			dp[u][i]=max(dp[v][i], dp[u][i]);
	}
	++dp[u][s[u]-'a'];
	for(int i=0; i<26; ++i)
		ans=max(dp[u][i], ans);
	act[u]=0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m >> s;
	for(int i=0; i<m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		graph[x].push_back(y);
	}
	for(int i=0; i<n; ++i)
		if(!vis[i])
			dfs1(i);
	cout << ans;
}