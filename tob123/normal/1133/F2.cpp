#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200000;
int p[N];
int n, e;
int find(int u) {
	if (p[u] == u)
		return u;
	return p[u] = find(p[u]);
}
int main() {
	int k;
	scanf("%d%d%d", &n, &e, &k);
	vector<vector<int> > g;
	g.resize(n);
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (int i = 0, a, b; i < e; ++i) {
		scanf("%d%d", &a, &b);
		--a; --b;
		g[a].push_back(b);
		swap(a, b);
		g[a].push_back(b);
		if (a != 0 && b != 0)
			p[find(a)] = find(b);
	}
	vector<pair<int, int> > sol;
	for (int i = 0; i < g[0].size(); ++i) {
		if (find(g[0][i]) != find(0)) {
			p[find(0)] = find(g[0][i]);
			sol.push_back({ 0,g[0][i] });
		}
	}
	if (sol.size() > k) {
		puts("NO");
		return 0;
	}
	for (int i = 0; i < n; ++i)
		p[i] = i;
	for (auto &e : sol)
		p[find(e.first)] = find(e.second);
	for (int i = 0; i < g.size(); ++i) {
		for (auto j : g[i]) {
			if (j == 0)
				continue;
			int u = find(i);
			int v = find(j);
			if (u != v) {
				if (i == 0 && sol.size() == k)
					continue;
				p[u] = v;
				sol.push_back({ i,j });
			}
		}
		if (i == 0 && sol.size() != k) {
			sol.resize(n);
			break;
		}
	}
	if (sol.size() != n - 1) {
		puts("NO");
		return 0;
	}
	puts("YES");
	for (auto e : sol)
		printf("%d %d\n", e.first + 1, e.second + 1);
	return 0;
}