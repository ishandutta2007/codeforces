#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

const int N = 5e5 + 2020;
const int P = 1e9 + 7;

int n, m, inf[N], dp[N], id[N], vis[N];
vector<int> e[N], r[N], com[N], ord;

void dfs(int u) {
	vis[u] = 1;
	for (auto v : e[u])
		if (!vis[v])
			dfs(v);
	ord.push_back(u);
}

void dfs2(int u, int c) {
	vis[u] = 1;
	id[u] = c;
	com[c].push_back(u);
	for (auto v : r[u])
		if (!vis[v])
			dfs2(v, c);
}

void solve() {
	cin >> n >> m;
	rep(i, 0, n) {
		com[i].clear();
		e[i].clear();
		r[i].clear();
		vis[i] = 0;
		inf[i] = 0;
		dp[i] = 0;
	}
	ord.clear();

	while (m--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a].push_back(b);
		r[b].push_back(a);
	}

	
	rep(i, 0, n)
		if (!vis[i])
			dfs(i);

	rep(i, 0, n)
		vis[i] = 0;

	reverse(ord.begin(), ord.end());

	int color = 0;
	rep(i, 0, n) {
		int u = ord[i];
		if (!vis[u]) 
			dfs2(u, color++);
	}


	rep(i, 0, color) {

		for (auto u : com[i]) {
			if (u == 0) 
				dp[i] = 1;
			
			for (auto v : e[u]) {
				if (id[u] == id[v])
					inf[id[u]] = 1;
			}
		}

		for (auto u : com[i])
			for (auto v : e[u]) {
				if (inf[id[u]] && dp[i]) {
					inf[id[v]] = 1;
				}
				dp[id[v]] = (dp[id[v]] + dp[i]) % P;
			}
	}

	rep(i, 0, n) {
		int j = id[i];
		int res;
		if (dp[j] == 0)
			res = 0;
		if (dp[j] == 1)
			res = 1;
		if (dp[j] > 1 && !inf[j])
			res = 2;
		if (dp[j] > 0 && inf[j])
			res = -1;
		cout << res << " ";
	}
	cout << "\n";
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}