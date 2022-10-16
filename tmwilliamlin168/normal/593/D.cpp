#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, eu[mxN], ev[mxN], p[mxN], pe[mxN], dp[mxN], d[mxN];
vector<int> adj[mxN];
ll ew[mxN];

int find(int x) {
	return x^dp[x]?dp[x]=find(dp[x]):x;
}

void join(int x, int y) {
	dp[x]=find(y);
}

void dfs(int u=0) {
	for(int e : adj[u]) {
		int v=eu[e]^ev[e]^u;
		if(v^p[u]) {
			p[v]=u;
			pe[v]=e;
			d[v]=d[u]+1;
			dfs(v);
			if(ew[e]<2)
				join(v, u);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i=1; i<n; ++i) {
		cin >> eu[i] >> ev[i] >> ew[i], --eu[i], --ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}
	iota(dp, dp+n, 0);
	dfs();
	while(m--) {
		int qt;
		cin >> qt;
		if(qt==1) {
			int a, b;
			ll y;
			cin >> a >> b >> y, --a, --b;
			while(y&&a^b) {
				if(d[a]<d[b])
					swap(a, b);
				y/=ew[pe[a]];
				a=find(p[a]);
			}
			cout << y << "\n";
		} else {
			int e;
			ll c;
			cin >> e >> c;
			ew[e]=c;
			if(c<2) {
				if(p[eu[e]]==ev[e])
					join(eu[e], ev[e]);
				else
					join(ev[e], eu[e]);
			}
		}
	}
}