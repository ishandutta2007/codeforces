#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int MAX_N = 1e5 + 7, INF = 1e18;
vector <int> g[MAX_N];
int s[MAX_N];
int par[MAX_N];
int val[MAX_N];

void dfs(int v, int d = 1, int prev = -1) {
	if (d % 2 == 0) {
		int mini = INF;
		for (int u : g[v]) {
			if (s[u] - s[prev] < 0) {
				cout << "-1" << endl;
				exit(0);
			}
			mini = min(mini, s[u] - s[prev]);
		}
		if (g[v].empty()) {
			val[v] = 0;
			return;
		}
		val[v] = mini;
		for (int u : g[v]) val[u] = (s[u] - s[prev]) - val[v];
	}
	for (int u : g[v]) {
		dfs(u, d + 1, v);
	}
}

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		g[par[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> s[i];
	val[1] = s[1];
	dfs(1);
	int s = 0;
	for (int i = 1; i <= n; i++) s += val[i];
	cout << s << endl;
	return 0;
}