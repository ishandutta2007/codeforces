#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int LOGN = 18;
const int INF = 1e9;

int dep[MX], time_in[MX], time_out[MX], par[LOGN][MX], t, logn;
int infected[MX], dist[MX], virus[MX];
vector<array<int, 2>> adj_cmp[MX];
int v[MX], s[MX], u[MX];
vector<int> adj[MX];

void dfs(int u) {
	time_in[u] = ++t;
	for (auto c : adj[u]) {
		if (c != par[0][u]) {
			dep[c] = dep[u] + 1;
			par[0][c] = u;
			dfs(c);
		}
	}
	time_out[u] = t;
}

bool is_anc(int u, int v) {
	return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

int lca(int u, int v) {
	if (is_anc(u, v))
		return u;
	if (is_anc(v, u))
		return v;
	for (int i = logn - 1; i >= 0; --i) {
		if (!is_anc(par[i][u], v)) {
			u = par[i][u];
		}
	}
	return par[0][u];
}

bool cmp_euler(int a, int b) {
	return time_in[a] < time_in[b];
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

	dfs(1);
	time_out[0] = t;
	for (logn = 1; (1 << logn) <= n; ++logn) {
		for (int i = 1; i <= n; ++i) {
			par[logn][i] = par[logn - 1][par[logn - 1][i]];
		}
	}

	fill(dist, dist + 1 + n, INF);
	fill(infected, infected + 1 + n, INF);

	int q;
	cin >> q;
	while (q--) {
		int k, m;
		cin >> k >> m;

		vector<int> pts;
		priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
		for (int i = 1; i <= k; ++i) {
			cin >> v[i] >> s[i];
			pts.push_back(v[i]);
			infected[v[i]] = 0;
			dist[v[i]] = 0;
			virus[v[i]] = i;
			pq.push({0, i, v[i]});
		}

		for (int i = 0; i < m; ++i) {
			cin >> u[i];
			pts.push_back(u[i]);
		}

		sort(pts.begin(), pts.end(), cmp_euler);
		for (int i = 1; i < k + m; ++i) {
			pts.push_back(lca(pts[i], pts[i - 1]));
		}
		sort(pts.begin(), pts.end(), cmp_euler);
		pts.erase(unique(pts.begin(), pts.end()), pts.end());

		vector<int> stk;
		for (auto i : pts) {
			if (!stk.empty()) {
				while (!is_anc(stk.back(), i)) {
					stk.pop_back();
				}
				int j = stk.back();
				adj_cmp[i].push_back({j, dep[i] - dep[j]});
				adj_cmp[j].push_back({i, dep[i] - dep[j]});
			}
			stk.push_back(i);
		}

		while (!pq.empty()) {
			auto [d, i, u] = pq.top();
			pq.pop();
			if (i != virus[u])
				continue;

			for (auto [v, w] : adj_cmp[u]) {
				int time_new = (dist[u] + w - 1) / s[i] + 1;
				if (make_pair(time_new, i) < make_pair(infected[v], virus[v])) {
					dist[v] = dist[u] + w;
					infected[v] = time_new;
					virus[v] = i;
					pq.push({time_new, i, v});
				}
			}
		}

		for (int i = 0; i < m; ++i) {
			cout << virus[u[i]] << ' ';
		}
		cout << '\n';

		for (auto i : pts) {
			infected[i] = INF;
			dist[i] = INF;
			virus[i] = 0;
			adj_cmp[i].clear();
		}
	}
}