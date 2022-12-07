#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, sz[N], f[N], par[N], ban[N];
vector<pair<int, int>> e[N];
pair<int, int> x;

int dfs(int v, int k) {
	sz[v] = 1;
	for (auto [u, id] : e[v]) 
		if (u != par[v] && !ban[id]) {
			par[u] = v;
			sz[v] += dfs(u, k);
			if (sz[u] == f[k - 2] || sz[u] == f[k - 1])
				x = {u, id};
		}
	return sz[v];
}				

bool solve(int v, int k) {
	if (k <= 2)
		return 1;
	x = {0, 0};
	par[v] = 0;
	dfs(v, k);
	if (x.first == 0) 
		return 0;
	int a = x.first;
	int b = par[a];
	int sa = k - 1;
	int sb = k - 2;
	if (f[k - 1] != sz[a])
		swap(sa, sb);
	ban[x.second] = 1;
	return solve(a, sa) && solve(b, sb);
}		

int main() {
	cin >> n;
	rep(i, 1, n) {
		int a, b;
		cin >> a >> b;
		e[a].emplace_back(b, i);
		e[b].emplace_back(a, i);
	}
	f[0] = f[1] = 1;
	rep(i, 2, 30)
		f[i] = f[i - 1] + f[i - 2];
	int k = 0;
	while (f[k] < n) k++;
	cout << (f[k] == n && solve(1, k) ? "YES" : "NO");
	return 0;
}