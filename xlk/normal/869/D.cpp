#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
vector<int> a[1020];
int n, m, x[9], y[9], s[1020], p = 1000000007;
long long ans = 0;
bool v[1020];
int id(int x) {
	if (g.find(x) == g.end()) {
		int u = g.size();
		g[x] = u;
	}
	return g[x];
}

void gao(int x) {
	for (; x > 0; x /= 2) {
		id(x);
	}
}

void dfs(int x, long long b) {
	v[x] = true;
	ans += b * s[x];
	ans %= p;
	for (int i: a[x]) {
		if (!v[i]) {
			dfs(i, b);
		}
	}
	v[x] = false;
}

int calc(int x) {
	int L = x, R = x, z = 0;
	for (; L <= n; L = L * 2, R = R * 2 + 1) {
		z += min(n, R) - L + 1;
	}
	return z;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x[i], &y[i]);
		gao(x[i]);
		gao(y[i]);
		a[g[x[i]]].push_back(g[y[i]]);
		a[g[y[i]]].push_back(g[x[i]]);
	}
	gao(1);
	for (pair<int, int> i: g) {
		s[i.second] = calc(i.first);
		if (g.count(i.first * 2)) {
			s[i.second] -= calc(i.first * 2);
		}
		if (g.count(i.first * 2 + 1)) {
			s[i.second] -= calc(i.first * 2 + 1);
		}
		if (i.first > 1) {
			a[g[i.first / 2]].push_back(g[i.first]);
			a[g[i.first]].push_back(g[i.first / 2]);
		}
	}
	for (int i = 0; i < g.size(); i++) {
		dfs(i, s[i]);
	}
	printf("%lld\n", ans);
	return 0;
}