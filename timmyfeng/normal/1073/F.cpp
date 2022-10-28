#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;

int par[MX], dep[MX], val[MX], leaf[MX][2], len, last;
vector<int> adj[MX], pt;
bool dead[MX], vstd[MX];

void dfsDel(int u, int p) {
	if (vstd[u] || adj[u].size() >= 3u)
		return;
	vstd[u] = true;
	++len;
	for (auto c : adj[u]) {
		if (c == p)
			continue;
		dfsDel(c, u);
		dead[u] = dead[c];
		return;
	}
	last = u;
	dead[u] = true;
}

void dfs(int u) {
	for (auto c : adj[u]) {
		if (c == par[u] || dead[c])
			continue;
		par[c] = u;
		dep[c] = dep[u] + 1;
		dfs(c);
	}
}

bool cmp(int a, int b) {
	return val[a] > val[b];
}

pair<int, int> dfsLeaf(int u, int p) {
	pair<int, int> res = {dep[u], u};
	for (auto c : adj[u]) {
		if (c == p || dead[c])
			continue;
		auto chd = dfsLeaf(c, u);
		if (chd.first > res.first || (chd.first == res.first && cmp(chd.second, res.second))) {
			res = chd;
		}
	}
	return res;
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

	int rt = 0;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() >= 3u) {
			rt = i;
			vector<pair<int, int>> chd;
			for (auto c : adj[i]) {
				len = 0;
				last = 0;
				dfsDel(c, i);
				if (dead[c]) {
					chd.emplace_back(len, last);
				}
			}
			if (chd.size() == adj[i].size() - 1u) {
				sort(chd.begin(), chd.end(), greater<pair<int, int>>());
				for (int j = 0; j < 2; ++j) {
					val[i] += chd[j].first;
					leaf[i][j] = chd[j].second;
				}
			}
		}
	}

	dfs(rt);
	rt = max_element(dep, dep + n + 1) - dep;
	par[rt] = 0;
	dep[rt] = 0;
	dfs(rt);
	rt = max_element(dep, dep + n + 1) - dep;

	int m = dep[rt];
	for (int i = 0; i < m / 2; ++i) {
		rt = par[rt];
	}

	par[rt] = 0;
	dep[rt] = 0;
	dfs(rt);
	for (auto c : adj[rt]) {
		if (dead[c])
			continue;
		auto res = dfsLeaf(c, rt);
		if (res.first == (m + 1) / 2) {
			pt.push_back(res.second);
			if (m % 2) {
				res = dfsLeaf(rt, c);
				pt.push_back(res.second);
			}
		}
	}

	sort(pt.begin(), pt.end(), cmp);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			cout << leaf[pt[j]][i] << ' ';
		}
		cout << '\n';
	}
}