#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
using namespace std;

const int N = 200111;

int t, n, m, a[N], b[N], vis[N], c[N];
vector<int> e[N];

bool dfs(int v) {
	vis[v] = 1;
	bool bi = 1;
	for (auto u : e[v]) {
		if (!vis[u]) {
			c[u] = c[v] ^ 1;
			bi &= dfs(u);
		}
		if (c[u] == c[v])
			bi = 0;
	}
	return bi;
}

void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	rep(i, 1, n) e[i].clear(), vis[i] = c[i] = 0;
	rep(i, 1, m) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	bool BI = dfs(1);
	ll s1 = 0, s2 = 0;
	rep(i, 1, n) {
		if (c[i]) s1 += a[i] - b[i];
		else s2 += a[i] - b[i];
	}	
	if ((accumulate(a + 1, a + n + 1, 0ll) + (1ll << 60)) % 2 == (accumulate(b + 1, b + n + 1, 0ll) + (1ll << 60)) % 2 && (!BI || s1 == s2))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	cin >> t;
	while (t--) solve();	
	return 0;
}