// Problem: C.    
// Contest: Codeforces - Codeforces Round #808 (Div. 1)
// URL: https://codeforces.com/contest/1707/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
const int L = 17;
int up[1<<L][L];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//weights unique -> mst unique
	//root tree at x
	//now check that all non-tree edges are back edges
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> edges(m), bad;
	vector<vector<int>> g(n);
	vector<int> tin(n), tout(n), h(n);
	int _timer = 0;
	dsu d(n);
	for(auto &[f, t] : edges) {
		cin >> f >> t;
		f--, t--;
		if(d.join(f, t)) {
			g[f].push_back(t);
			g[t].push_back(f);
		} else bad.push_back({f, t});
	}
	for(int i = 0; i < L; i++) up[n][i] = n;
	auto dfs = [&](auto self, int v) -> void {
		for(int i = 1; i < L; i++)
			up[v][i] = up[up[v][i-1]][i-1];
		tin[v] = _timer++;
		for(auto i : g[v]) {
			g[i].erase(find(all(g[i]), v));
			up[i][0] = v;
			h[i] = h[v] + 1;
			self(self, i);
		}
		tout[v] = _timer;
	};
	up[0][0] = n;
	dfs(dfs, 0);
	auto par = [&](int u, int v) {
		return tin[u] <= tin[v] && tin[v] < tout[u];
	};
	vector<int> run(n+1);
	auto add = [&](int l, int r, int x) {//[l; r)
		if(l < r) {
			run[l] += x;
			run[r] -= x;
		}
	};
	for(auto &[u, v] : bad) {
		if(h[u] > h[v]) swap(u, v);
		if(par(u, v)) {
			add(0, n, 1);
			
			int dif = h[v] - h[u] - 1, s = v;
			for(int z = L; z--;) if(dif >= (1<<z))
				dif -= 1<<z, s = up[s][z];
			
			add(tin[s], tout[s], -1);
			add(tin[v], tout[v], 1);
		} else {
			add(tin[u], tout[u], 1);
			add(tin[v], tout[v], 1);
		}
	}
	for(int i = 1; i < n; i++) {
		run[i] += run[i-1];
	}
	for(int i = 0; i < n; i++)
		cout << (run[tin[i]] == bad.size());
	cout << '\n';
}