#include <bits/stdc++.h> 
using namespace std;

const int MX = 1 << 20;

vector<pair<int, int>> adj[MX];
int cnt[MX], pre[MX], a[MX];
vector<int> tour;
bool used[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i];
	}

	int k = 0;
	vector<int> ans;
	for (int i = 0; i <= 20; ++i) {
		int mx = 1 << i;
		fill(cnt, cnt + mx, 0);
		fill(pre, pre + mx, -1);
		fill(adj, adj + mx, vector<pair<int, int>>());
		fill(used, used + 2 * n, false);
		tour.clear();

		for (int j = 0; j < 2 * n; j += 2) {
			int u = a[j] % mx;
			int v = a[j ^ 1] % mx;
			adj[u].emplace_back(v, j ^ 1);
			adj[v].emplace_back(u, j);
		}

		bool bad = false;
		for (int j = 0; j < mx; ++j) {
			bad |= adj[j].size() % 2;
		}
		if (bad)
			break;

		vector<pair<int, int>> stk = {{a[0] % mx, -1}};
		vector<int> tour;
		while (!stk.empty()) {
			int u, p;
			tie(u, p) = stk.back();

			if (adj[u].empty()) {
				if (p != -1) {
					tour.push_back(p);
					tour.push_back(p ^ 1);
				}
				stk.pop_back();
				continue;
			}

			int v, i;
			tie(v, i) = adj[u].back();
			adj[u].pop_back();
			if (!used[i / 2]) {
				used[i / 2] = true;
				stk.emplace_back(v, i);
			}
		}
		if ((int)tour.size() < 2 * n)
			break;

		k = i;
		ans = tour;
	}

	cout << k << '\n';
	for (auto i : ans) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
}