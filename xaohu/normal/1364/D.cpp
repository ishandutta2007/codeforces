#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
const int N = 111000; 
 
int n, m, k, dep[N], fa[N];
vector<int> g[N], q[2];

void print(vector<int> ans) {
	for (auto x : ans)
		cout << x << " ";
}

void dfs(int v) {
	dep[v] = dep[fa[v]] + 1;
	q[dep[v] % 2].push_back(v);
	sort(g[v].begin(), g[v].end(), [&](int a, int b) {
		return dep[a] > dep[b];
	});
	for (auto u : g[v]) {
		if (dep[u] == 0) {
			fa[u] = v;
			dfs(u);
		}
		else if (fa[v] != u && dep[u] < dep[v]) {
			vector<int> ans;
			if (dep[v] - dep[u] + 1 <= k) {
				cout << "2\n" << dep[v] - dep[u] + 1 << "\n";
				while (v != fa[u]) {
					ans.push_back(v);
					v = fa[v];
				}
				print(ans);
				exit(0);
			}
			else {
				cout << "1\n";
				int p = 0;
				while (v != u) {
					if (!p)
						ans.push_back(v);
					p ^= 1;
					v = fa[v];
				}
				ans.resize((k + 1) / 2);
				print(ans);
				exit(0);
			}		
		}
	}
}
 
int main() {
	cin >> n >> m >> k;
	while (m--) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	if (q[0].size() < q[1].size())
		swap(q[0], q[1]);
	q[0].resize((k + 1) / 2);
	cout << "1\n";
	print(q[0]);
	return 0;
}