#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
ll t[mxN], h[mxN], dp1[mxN], dp2[mxN];
vector<int> adj[mxN];

ll solve(int u, vector<int> v1, vector<int> v2, vector<int> v3) {
	ll s=t[u]*(v1.size()+v2.size()+v3.size());
	for(int v : v1)
		s+=dp1[v];
	for(int v : v2)
		s+=dp2[v];
	for(int v : v3)
		s+=dp2[v];
	ll r=1e18;
	for(int i=0; i<=v3.size(); ++i) {
		if(i)
			s+=dp1[v3[i-1]]-dp2[v3[i-1]];
		r=min(s-min((int)v1.size()+i, (int)v2.size()+(int)v3.size()-i)*t[u], r);
	}
	return r;
}

void dfs(int u=0, int p=-1) {
	if(u)
		adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	vector<int> v1, v2, v3;
	for(int v : adj[u]) {
		dfs(v, u);
		if(h[v]<h[u])
			v1.push_back(v);
		else if(h[v]>h[u])
			v2.push_back(v);
		else
			v3.push_back(v);
	}
	sort(v3.begin(), v3.end(), [](const int &a, const int &b) {
		return dp1[a]-dp2[a]<dp1[b]-dp2[b];
	});
	if(u) {
		{
			v2.push_back(p);
			dp1[u]=solve(u, v1, v2, v3);
			v2.pop_back();
		}
		{
			v1.push_back(p);
			dp2[u]=solve(u, v1, v2, v3);
			v1.pop_back();
		}
	} else
		cout << solve(u, v1, v2, v3);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> t[i];
	for(int i=0; i<n; ++i)
		cin >> h[i];
	for(int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
}