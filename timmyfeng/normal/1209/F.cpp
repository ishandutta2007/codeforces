#include <bits/stdc++.h>
using namespace std;

const int MX = 2e6 + 1;
const int M = 1e9 + 7;

vector<int> adj[MX][10];
int ans[MX];

int add(int a, int b) {
	a += b;
	if (a >= M) {
		a -= M;
	}
	return a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int cnt = n;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;

		string lab = to_string(i);

		int cur_a = u;
		int cur_b = v;
		for (int j = 0; j < int(lab.size()) - 1; ++j) {
			int d = lab[j] - '0';
			adj[cur_a][d].push_back(++cnt);
			cur_a = cnt;
			adj[cur_b][d].push_back(++cnt);
			cur_b = cnt;
		}

		int d = lab.back() - '0';
		adj[cur_a][d].push_back(v);
		adj[cur_b][d].push_back(u);
	}

	queue<vector<int>> que;
	que.push({1});
	memset(ans, -1, sizeof ans);
	ans[1] = 0;

	while (!que.empty()) {
		vector<int> cur = que.front();
		que.pop();
		for (int i = 0; i < 10; ++i) {
			vector<int> nxt;
			for (auto u : cur) {
				for (auto v : adj[u][i]) {
					if (ans[v] == -1) {
						ans[v] = add(mul(ans[cur[0]], 10), i);
						nxt.push_back(v);
					}
				}
			}

			if (!nxt.empty()) {
				que.push(nxt);
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		cout << ans[i] << "\n";
	}
}