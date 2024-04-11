#include <bits/stdc++.h> 
using namespace std;

const int MX = 1000 + 1;

vector<int> adj[MX];
int time_out[MX];
int time_in[MX];
int dep[MX];
int t;

void dfs(int u, int p) {
	time_in[u] = ++t;
	for (auto c : adj[u]) {
		if (c != p) {
			dep[c] = dep[u] + 1;
			dfs(c, u);
		}
	}
	time_out[u] = t;
}

bool is_anc(int u, int v) {
	return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

void solve() {
	int n;
	cin >> n;

	fill(adj + 1, adj + n + 1, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> ask;
	auto qry = [&]() {
		if (ask.empty()) {
			return make_pair(1, int(1e9));
		}

		cout << "? " << ask.size();
		for (auto i : ask) {
			cout << " " << i;
		}
		cout << endl;

		pair<int, int> res;
		cin >> res.first >> res.second;
		return res;
	};

	for (int i = 1; i <= n; ++i) {
		ask.push_back(i);
	}
	auto [rt, dist] = qry();

	t = 0;
	dep[rt] = 0;
	dfs(rt, 0);

	ask.clear();
	for (int i = 1; i <= n; ++i) {
		if (dep[i] == 1) {
			ask.push_back(i);	
		}
	}

	int branch = qry().first;	

	int lb = 1, rb = n - 1;
	while (lb <= rb) {
		int mb = (lb + rb) / 2;

		ask.clear();
		for (int i = 1; i <= n; ++i) {
			if (is_anc(branch, i) && dep[i] >= mb) {
				ask.push_back(i);
			}
		}

		if (qry().second == dist) {
			lb = mb + 1;
		} else {
			rb = mb - 1;
		}
	}

	ask.clear();
	for (int i = 1; i <= n; ++i) {
		if (is_anc(branch, i) && dep[i] == rb) {
			ask.push_back(i);
		}
	}
	int ans_u = qry().first;

	ask.clear();
	for (int i = 1; i <= n; ++i) {
		if (!is_anc(branch, i) && dep[i] == dist - rb) {
			ask.push_back(i);
		}
	}
	int ans_v = qry().first;

	cout << "! " << ans_u << " " << ans_v << endl;

	string verdict;
	cin >> verdict;
	assert(verdict == "Correct");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}