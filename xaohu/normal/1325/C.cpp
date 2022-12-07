#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n, ans[111000];
vector<pair<int, int>> g[111000]; 
vector<int> ids;

bool dfs(int v, int p) {
	bool leaf = true;
	for (auto [u, id] : g[v]) 
		if (u != p) {
			leaf = false;
			if (dfs(u, v))
				ids.push_back(id);
		}		
	return leaf;
}
		

int main() {
	cin >> n;
	rep(i, 1, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	int root = 0;
	rep(i, 1, n)
		if (g[i].size() > 1)
			root = i;
	if (root)
		dfs(root, 0);
	memset(ans, -1, sizeof ans);
	int x = 0;
	if (ids.size() >= 3) {
		x = 3;
		rep(i, 0, 2)
			ans[ids[i]] = i;
	}
	rep(i, 1, n - 1) {
		if (ans[i] == -1)
			ans[i] = x++;
		cout << ans[i] << "\n";
	}
	return 0;
}