#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

vector<int> adj[MX], dist1, dist2;
vector<array<int, 2>> ops;
bool save[MX];
int par[MX], best;
int pt1, pt2;
ll ans;

void dfs(int u, vector<int>& dep) {
	for (auto c : adj[u]) {
		if (c != par[u]) {
			dep[c] = dep[u] + 1;
			par[c] = u;
			dfs(c, dep);
		}
	}
}

void dfs_ans(int u) {
	for (auto c : adj[u]) {
		if (c != par[u]) {
			dfs_ans(c);
		}
	}

	if (!save[u]) {
		if (dist1[u] > dist2[u]) {
			ops.push_back({pt1, u});
			ans += dist1[u];
		} else {
			ops.push_back({pt2, u});
			ans += dist2[u];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dist1.resize(n + 1);
	dfs(1, dist1);
	pt1 = max_element(dist1.begin(), dist1.end()) - dist1.begin();

	dist1[pt1] = 0;
	par[pt1] = 0;
	dfs(pt1, dist1);
	pt2 = max_element(dist1.begin(), dist1.end()) - dist1.begin();

	dist2.resize(n + 1);
	par[pt2] = 0;
	dfs(pt2, dist2);

	for (int i = pt1; i; i = par[i]) {
		save[i] = true;
	}

	dfs_ans(pt2);
	for (int i = pt1; i != pt2; i = par[i]) {
		ops.push_back({pt2, i});
		ans += dist2[i];
	}

	cout << ans << '\n';
	for (auto i : ops) {
		cout << i[0] << ' ' << i[1] << ' ' << i[1] << '\n';
	}
}