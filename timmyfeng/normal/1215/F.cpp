#include <bits/stdc++.h>
using namespace std;

const int MX = 4e5;

vector<int> adj[4 * MX + 2], jda[4 * MX + 2];
vector<int> stk, ans;
bool vstd[4 * MX + 2];
int comp[4 * MX + 2];
int cur;

void disjun(int u, int v) {
	adj[u ^ 1].push_back(v);
	adj[v ^ 1].push_back(u);
	jda[u].push_back(v ^ 1);
	jda[v].push_back(u ^ 1);
}

void dfs1(int u) {
	vstd[u] = true;
	for (auto c : adj[u]) {
		if (!vstd[c]) {
			dfs1(c);
		}
	}
	stk.push_back(u);
}

void dfs2(int u) {
	comp[u] = cur;
	for (auto c : jda[u]) {
		if (!comp[c]) {
			dfs2(c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, p, s, m;
	cin >> n >> p >> s >> m;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		disjun(a * 2, b * 2);
	}
	for (int i = 1; i <= p; ++i) {
		int a, b;
		cin >> a >> b;
		disjun(i * 2 + 1, (p + a) * 2);
		if (b != s) {
			disjun(i * 2 + 1, (p + b + 1) * 2 + 1);
		}
	}
	for (int i = 1; i < s; ++i) {
		disjun((p + i) * 2, (p + i + 1) * 2 + 1);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		disjun(a * 2 + 1, b * 2 + 1);
	}

	for (int i = 2; i <= (p + s) * 2 + 1; ++i) {
		if (!vstd[i]) {
			dfs1(i);
		}
	}
	while (!stk.empty()) {
		int u = stk.back();
		stk.pop_back();
		if (!comp[u]) {
			++cur;
			dfs2(u);
		}
	}

	int sig = 0;
	for (int i = 1; i <= p + s; ++i) {
		if (comp[i * 2] == comp[i * 2 + 1]) {
			cout << -1 << '\n';
			return 0;
		} else if (comp[i * 2] > comp[i * 2 + 1]) {
			if (i <= p) {
				ans.push_back(i);
			} else {
				sig = i - p;
			}
		}
	}
	cout << ans.size() << ' ' << sig << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}