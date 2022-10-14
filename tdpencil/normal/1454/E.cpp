#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<set<int>> g(n);
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<int> val(n, 1);
		queue<int> leafs;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == 1) {
				leafs.push(i);
			}
		}
		while (!leafs.empty()) {
			int v = leafs.front();
			leafs.pop();
			int to = *g[v].begin();
			val[to] += val[v];
			val[v] = 0;
			g[v].clear();
			g[to].erase(v);
			if (g[to].size() == 1) {
				leafs.push(to);
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += val[i] * 1ll * (val[i] - 1) / 2;
			ans += val[i] * 1ll * (n - val[i]);
		}
		cout << ans << endl;
	}
	
	return 0;
}