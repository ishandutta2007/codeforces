#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++) 

using namespace std;

const int N = 123000;

int t, n, dp[N][2], who[N], last;
vector<int> g[N], opt[N];
vector<tuple<int, int, int, int>> ans;

void calc(int v, int p) {
	opt[v].clear();
	
	int sum = 0;
	
	for (auto u : g[v]) {
		if (u != p) {
			calc(u, v);
			sum += dp[u][0];
			opt[v].push_back(u);
		}
	}
	
	sort(opt[v].begin(), opt[v].end(), [&](int a, int b) {
		return dp[a][1] - dp[a][0] < dp[b][1] - dp[b][0];
	});
	
	dp[v][0] = 1 + sum;
	rep(i, 0, min(1, (int)opt[v].size() - 1)) {
		int u = opt[v][i];
		dp[v][0] += dp[u][1] - dp[u][0];
	}
	
	dp[v][1] = sum;
	if (opt[v].size()) {
		int u = opt[v][0];
		dp[v][1] += dp[u][1] - dp[u][0];
	}
}

int Find(int v) {
	if (opt[v].empty())
		return v;
	return Find(opt[v][0]);
}

void solve(int v, int p, int x) {
	int e = v;
	int f = v;
	
	if (opt[v].size() > 0)
		e = opt[v][0];
	if (opt[v].size() > 1 && x == 0)
		f = opt[v][1];
		
	if (v != 1 && x == 0) {
		int f1 = (e != v ? Find(e) : v);
		int f2 = (f != v ? Find(f) : v);
		ans.push_back({v, p, f1, last});
		last = f2;
	}
	
	if (e != v)
		solve(e, v, 1);
	if (f != v)
		solve(f, v, 1);
	
	for (auto u : g[v])
		if (u != p && u != e && u != f)
			solve(u, v, 0);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n)
			g[i].clear();
		rep(i, 2, n) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		calc(1, 0);
		last = Find(1);
		ans.clear();
		solve(1, 0, 0);
		cout << ans.size() << "\n";
		for (auto [a, b, c, d] : ans)
			cout << a << " " << b << " " << c << " " << d << "\n";
	}
}