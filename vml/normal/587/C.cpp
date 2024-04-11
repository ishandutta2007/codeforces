#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#define ll long long
#define next nex 

using namespace std;

const int maxn = (int)1e5 + 10, maxlog = 19;

int p[maxlog][maxn];
int v[maxlog][maxn][10];
int sz[maxlog][maxn];
vector <int> ed[maxn];
vector <int> d[maxn];
int h[maxn];
int f[20];

void mer(int *a, int s, int *b, int s1, int *c, int s2) {
	merge(b, b + s1, c, c + s2, f);

	for (int i = 0; i < s; i++) {
		a[i] = f[i];
	}
}

void dfs(int w, int par, int hh) {
	p[0][w] = par;
	h[w] = hh;
	sz[0][w] = min(10, (int)d[w].size());

	for (int i = 0; i < sz[0][w]; i++) {
		v[0][w][i] = d[w][i];
	}

	for (int i = 1; i < maxlog; i++) {
		int pp = p[i - 1][w];
		sz[i][w] = min(10, sz[i - 1][w] + sz[i - 1][pp]);

		mer(v[i][w], sz[i][w], v[i - 1][w], sz[i - 1][w], v[i - 1][pp], sz[i - 1][pp]);

		p[i][w] = p[i - 1][pp];
	}

	for (int i = 0; i < (int)ed[w].size(); i++) {
		int u = ed[w][i];

		if (u != par) {
			dfs(u, w, hh + 1);
		}
	}
}

int lca(int u, int v) {
	if (u == v) {
		return u;
	}

	if (h[u] < h[v]) {
		swap(u, v);
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		int k = p[i][u];

		if (h[k] >= h[v]) {
			u = k;
		}
	}

	if (u == v) {
		return u;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		int k1 = p[i][u];
		int k2 = p[i][v];

		if (k1 != k2) {
			u = k1;
			v = k2;
		}
	}

	return p[0][u];
}

void go(int u, int l, int a[10], int &szz) {
	if (u == l) {
		return;
	}
	int now_sz = 0;
	int c[10];
	for (int i = maxlog - 1; i >= 0; i--) {
		int pp = p[i][u];

		if (h[pp] > h[l]) {
			int nsz = min(10, now_sz + sz[i][u]);

			mer(c, nsz, a, now_sz, v[i][u], sz[i][u]);
			for (int j = 0; j < 10; j++) {
				a[j] = c[j];
			}
			now_sz = nsz;
			u = pp;
		}
	}

	int nsz = min(10, now_sz + sz[0][u]);
	mer(c, nsz, a, now_sz, v[0][u], sz[0][u]);
	for (int i = 0; i < 10; i++) {
		a[i] = c[i];
	}
	now_sz = nsz;
	szz = now_sz;
}

int main() {
	int n, m, q;

	scanf("%d %d %d", &n, &m, &q);

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	for (int i = 1; i <= m; i++) {
		int x;

		scanf("%d", &x);

		d[x].push_back(i);
	}

	dfs(1, 1, 1);

	while (q--) {
		int u, w, a;

		scanf("%d %d %d", &u, &w, &a);

		int l = lca(u, w);

		int r[10];
		int b[10];
		int c[10];
		int sz1 = 0, sz2 = 0;

		go(u, l, b, sz1);
		go(w, l, c, sz2);

		int sz3 = sz[0][l];

		for (int i = 0; i < sz3; i++) {
			r[i] = v[0][l][i];
		}

		int ss = min(10, sz1 + sz3);

		int g[10];

		mer(g, ss, r, sz3, b, sz1);
		sz1 = ss;
		for (int i = 0; i < 10; i++) {
			b[i] = g[i];
		}
		ss = min(10, sz1 + sz2);
		mer(g, ss, b, sz1, c, sz2);

		printf("%d ", min(ss, a));

		for (int i = 0; i < min(ss, a); i++) {
			printf("%d ", g[i]);
		}
		printf("\n");
	}

	return 0;
}