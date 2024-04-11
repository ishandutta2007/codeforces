#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define double long double
typedef long long ll;
using namespace std;

const int N = 200000;

int t, n, m, vis[N], dep[N], bal[N], best[N], dp[N], ord[N];
vector<int> e[N];

bool dfs(int u) {
	vis[u] = 0;
	bool res = 1;
	for (auto v : e[u]) {
		if (vis[v] == 1)
			res = 0;
		if (vis[v] == -1)
			res &= dfs(v);
	}
	vis[u] = 1;
	return res;
}

int calc(int u) {
	best[u] = u;
	for (auto v : e[u]) {
		if (dep[v] == -1) {
			dep[v] = dep[u] + 1;
			bal[u] += calc(v);

			if (dep[best[u]] > dep[best[v]])
				best[u] = best[v];
		}
		else {
			bal[u]++;
			bal[v]--;

			if (dep[v] < dep[best[u]])
				best[u] = v;
		}
	}
	if (bal[u] > 1)
		dp[u] = 0;
	return bal[u];
}

void work(int u) {
	dp[u] &= dp[best[u]];
	for (auto v : e[u])
		if (dep[v] == dep[u] + 1)
			work(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	srand(233);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			e[i].clear();
			dep[i] = -1;
			bal[i] = 0;
			dp[i] = 1;
		}

		while (m--) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			e[a].push_back(b);
		}
		
		iota(ord, ord + n, 0);
		random_shuffle(ord, ord + n);
		int id = -1;
		for (int i = 0; i < min(100, n); i++) {
			fill(vis, vis + n, -1);
			if (dfs(ord[i])) {
				id = ord[i];
				break;
			}
		}

		if (id == -1) {
			cout << "-1\n";
			continue;
		}

		dep[id] = 0;
		calc(id);
		work(id);

		if (5 * count(dp, dp + n, 1) >= n) {
			for (int i = 0; i < n; i++)
				if (dp[i])
					cout << i + 1 << " ";
			cout << endl;
		}
		else {
			cout << "-1\n";
		}
	}
	return 0;
}