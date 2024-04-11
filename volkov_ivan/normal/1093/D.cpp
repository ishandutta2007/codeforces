#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

const int MAX_N = 3e5 + 7, M = 998244353;
vector <int> g[MAX_N];
bool visited[MAX_N];
int cnt_0, cnt_1;
int color[MAX_N];
int pow_2[MAX_N];

bool dfs(int v, int c) {
	color[v] = c;
	visited[v] = 1;
	if (c == 1) cnt_1++;
	else cnt_0++;
	for (int u : g[v]) {
		if (visited[u]) {
			if (color[u] == color[v]) return 0;
			continue;
		}
		if (!dfs(u, 1 - c)) return 0;
	}
	return 1;
}

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	pow_2[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		pow_2[i] = (pow_2[i - 1] * 2) % M;
	}
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = 1; j <= n; j++) {
			g[j].clear();
			visited[j] = 0;
		}
		for (int j = 0; j < m; j++) {
			int v, u;
			cin >> v >> u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		int ans = 1;
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			cnt_0 = 0, cnt_1 = 0;
			if (!dfs(i, 0)) {
				cout << 0 << endl;
				flag = 1;
				break;
			}
			int now = (pow_2[cnt_0] + pow_2[cnt_1]) % M;
			ans = (ans * now) % M;
		}
		if (!flag) cout << ans << '\n';
	}
	return 0;
}