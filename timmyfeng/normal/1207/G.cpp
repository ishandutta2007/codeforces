#include <bits/stdc++.h>
using namespace std;

const int MX = 4e5;

int link[MX + 1], tin[MX + 1], tout[MX + 1], ft[MX + 2], ans[MX];
vector<int> qtree[MX + 1], stree[MX + 1];
vector<pair<int, int>> ques[MX + 1];
int to[MX + 1][26];
char let[MX + 1];
int sz = 1, t = 0;

int query(int a) {
	int res = 0;
	for ( ; a; a -= a & -a) {
		res += ft[a];
	}
	return res;
}

void upd(int a, int val) {
	for ( ; a <= t; a += a & -a) {
		ft[a] += val;
	}
}

void dfs1(int u) {
	tin[u] = ++t;
	for (auto c : qtree[u]) {
		dfs1(c);
	}
	tout[u] = t;
}

void dfs2(int u, int cur) {
	upd(tin[cur], 1);
	for (auto [a, b] : ques[u]) {
		ans[b] = query(tout[a]) - query(tin[a] - 1);
	}
	for (auto c : stree[u]) {
		dfs2(c, to[cur][let[c] - 'a']);
	}
	upd(tin[cur], -1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			stree[0].push_back(i);
			cin >> let[i];
		} else {
			int p;
			cin >> p;
			stree[p].push_back(i);
			cin >> let[i];
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int a;
		string s;
		cin >> a >> s;
		int cur = 0;
		for (auto j : s) {
			if (!to[cur][j - 'a']) {
				to[cur][j - 'a'] = sz++;
			}
			cur = to[cur][j - 'a'];
		}
		ques[a].emplace_back(cur, i);
	}

	queue<int> que;
	que.push(0);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (int i = 0; i < 26; ++i) {
			if (to[u][i]) {
				link[to[u][i]] = u ? to[link[u]][i] : 0;
				qtree[link[to[u][i]]].push_back(to[u][i]);
				que.push(to[u][i]);
			} else {
				to[u][i] = to[link[u]][i];
			}
		}
	}

	dfs1(0);
	dfs2(0, 0);

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}