#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n;
ll w[mxN], dp[mxN], ans;
vector<ar<int, 2>> adj[mxN];

void dfs1(int u, int p) {
	for(ar<int, 2> e : adj[u]) {
		int v=e[0];
		if(v==p)
			continue;
		dfs1(v, u);
		dp[u]=max(dp[v]-e[1], dp[u]);
	}
	dp[u]+=w[u];
	ans=max(dp[u], ans);
}

struct mex {
	ar<ll, 2> a={}, b={};
	void ins(ar<ll, 2> c) {
		if(c>a)
			swap(c, a);
		if(c>b)
			swap(c, b);
	}
	ll qry(ll i) {
		return a[1]==i?b[0]:a[0];
	}
};

void dfs2(int u, int p, ll a) {
	ans=max(a, ans);
	mex m;
	for(ar<int, 2> e : adj[u]) {
		int v=e[0];
		if(v==p)
			continue;
		m.ins({dp[v]-e[1]+w[u], v});
	}
	for(ar<int, 2> e : adj[u]) {
		int v=e[0];
		if(v==p)
			continue;
		dfs2(v, u, max(a, m.qry(v))-e[1]+w[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i)
		cin >> w[i];
	for(int i=0; i<n-1; ++i) {
		int ui, vi, ci;
		cin >> ui >> vi >> ci, --ui, --vi;
		adj[ui].push_back({vi, ci});
		adj[vi].push_back({ui, ci});
	}
	dfs1(0, -1);
	dfs2(0, -1, w[0]);
	cout << ans;
}