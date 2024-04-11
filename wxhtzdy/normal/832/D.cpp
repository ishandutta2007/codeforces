#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 17, lg = 17;
 
int n, q, par[maxn][lg], h[maxn], ver[3];
vector<int> g[maxn];
void dfs(int v = 0){
	for(int i = 1; i < lg; i++)
		par[v][i] = par[ par[v][i - 1] ][i - 1];
	for(auto u : g[v]){
		h[u] = h[v] + 1;
		par[u][0] = v;
		dfs(u);
	}
}
int lca(int v, int u){
	if(h[v] > h[u])  swap(v, u);
	for(int i = 0; i < lg; i++)
		if(h[u] - h[v] >> i & 1)
			u = par[u][i];
	for(int i = lg - 1; i >= 0; i--)
		if(par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return v == u ? v : par[v][0];
}
int calc(int f, int s, int t){
	int ans = 0;
	bool is1 = lca(f, s) == f, is2 = lca(f, t) == f;
	if(is1 != is2)  return 1;
	if(is1)
		ans = max(ans, h[ lca(s, t) ] - h[ f ]);
	else if(lca(f, s) != lca(f, t))
		ans = max(ans, h[ f ] - max(h[ lca(f, s) ], h[ lca(f, t) ]));
	else
		ans = max(ans, h[ f ] + h[ lca(s, t) ] - 2 * h[ lca(f, t) ]);
	return ans + 1;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for(int i = 1, p; i < n; i++){
		cin >> p, p--;
		g[p].push_back(i);
	}
	dfs();
	while(q--){
		for(int i = 0; i < 3; i++)
			cin >> ver[i], ver[i]--;
		cout << max({calc(ver[0], ver[1], ver[2]), calc(ver[1], ver[0], ver[2]), calc(ver[2], ver[1], ver[0])}) << '\n';
	}
	return 0;
}