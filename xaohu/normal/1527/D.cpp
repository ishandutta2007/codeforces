#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

const int N = 200005;

int t, n, fa[N], vis[N];
vector<int> g[N];
long long ans[N], sz[N];

void dfs(int v) {
	sz[v] = 1;
	for (auto u : g[v]) {
		if (u != fa[v]) {
			fa[u] = v;
			dfs(u);
			sz[v] += sz[u];
		}
	}
}	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 0, n) {
			g[i].clear();
			ans[i] = vis[i] = 0;
		}
		rep(i, 1, n - 1) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		dfs(0);
		for (auto u : g[0])
			ans[0] += sz[u] * (sz[u] - 1) / 2;
		ans[1] = 1ll * n * (n - 1) / 2 - ans[0];
		int a = 0, b = 0;
		long long c = 0, d = 0;
		vis[0] = 1;
		rep(i, 1, n - 1) {
			if (vis[i]) {
				ans[i + 1] = c * d;
				continue;
			}
			int v = i, lst;
			while (!vis[v]) {
				vis[v] = 1;
				lst = v;
				v = fa[v];
			}
			if (v != a && v != b) 
				break;
			if (v != a) {
				swap(a, b);
				swap(c, d);
			}
			if (!a && !b) {
				a = i;
				c = sz[i];
				d = sz[0] - sz[lst];
			}
			else {
				a = i;
				c = sz[i];
			}
			ans[i + 1] = c * d;
		}
		rep(i, 1, n - 1)
			ans[i] -= ans[i + 1];
		rep(i, 0, n)
			cout << ans[i] << " "; 
		cout << "\n";
	}
	return 0;
}