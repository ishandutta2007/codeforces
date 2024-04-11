#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long int;
const int mod = 1e9+7;
const int N = 5e4 + 5;
int a[N], in[N], out[N], b[N], lst[N], dep[N];
int T = 1;
void dfs(vector<vector<int>> &g, int u, int v)
{
	in[u] = T++;
	b[in[u]] = a[u];
	if (v) dep[in[u]] = 1 + dep[in[v]];
	for (auto x : g[u]) {
		if (x == v) continue;
		dfs(g, x, u);
	}
	out[u] = T;
}
 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
 
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		lst[i] = -2*N;
	}
	vector<vector<int>> g(n+1);
	for (int i = 2; i <= n; ++i) {
		int par; cin >> par;
		g[par].push_back(i);
		g[i].push_back(par);
	}
	dfs(g, 1, 0);
	for (int tm = 1; tm <= q; ++tm) {
		int u; cin >> u;
		int sm = 0, ct = 0;
		int d = dep[in[u]];
		for (int i = in[u]; i < out[u]; ++i) {
			int mul = (lst[i]+b[i] <= tm);
			sm += mul*dep[i];
			ct += mul;
			lst[i] = mul ? tm : lst[i];
		}
		cout << sm-ct*d << ' ' << ct << '\n';
	}
}