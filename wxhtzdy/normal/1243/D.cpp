#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
vector<int> g[N];
int n, m;
set<int> setik;
int par[N];
int sz[N];
int cnt[N];

int root(int u) {
	return par[u] == u ? u : par[u] = root(par[u]);
}

void unite(int x, int y) {
	x = root(x);
	y = root(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x, y);
	setik.erase(setik.find(x));
	sz[y] += sz[x];
	par[x] = y;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
		setik.insert(i);
		for (int x : g[i]) {
			int y = root(x);
			cnt[y] += 1;
		}
		vector<int> vec;
		for (int p : setik) {
			if (sz[p] > cnt[p]) {
				vec.push_back(p);
			}
		}
		for (int x : g[i]) {
			int y = root(x);
			cnt[y] -= 1;
		}
		for (int qq : vec) {
			unite(qq, i);
		}
	}
	set<int> setik;
	for (int i = 1; i <= n; i++)
		setik.insert(root(i));
	printf("%d", setik.size() - 1);
	return 0;
}