#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
int v[maxn];
int tin[maxn];
int tout[maxn];

vector <int> ed[maxn];
int tt = -1;

void dfs(int x, int p) {
	tt++;
	tin[x] = tt;

	for (int i = 0; i < (int)ed[x].size(); i++) {
		int u = ed[x][i];

		if (u != p) {
			dfs(u, x);
		}
	}

	tout[x] = tt;
}

int x[maxn];

bitset <1000> tr[4 * maxn];
int st[4 * maxn];
int m;

void build(int it, int l, int r) {
	if (l == r) {
		tr[it][x[l]] = 1;
	} else {
		int m = (l + r) >> 1;

		build((it << 1), l, m);
		build((it << 1) + 1, m + 1, r);

		tr[it] = tr[(it << 1)] | tr[(it << 1) + 1];
	}
}

void sets(int it, int x) {
	st[it] += x;
	st[it] %= m;

	tr[it] = (tr[it] << x) | (tr[it] >> (m - x));
}

void push(int it) {
	if (st[it] != 0) {
		sets((it << 1), st[it]);
		sets((it << 1) + 1, st[it]);

		st[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm, int z) {
	if (l == lm && r == rm) {
		sets(it, z);
	} else {
		push(it);

		int m = (l + r) >> 1;

		if (rm <= m) {
			change((it << 1), l, m, lm, rm, z);
		} else if (lm > m) {
			change((it << 1) + 1, m + 1, r, lm, rm, z);
		} else {
			change((it << 1), l, m, lm, m, z);
			change((it << 1) + 1, m + 1, r, m + 1, rm, z);
		}

		tr[it] = tr[(it << 1)] | tr[(it << 1) + 1];
	}
}

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

bitset <1000> ans;
bitset <1000> pr;

void go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		ans |= tr[it];
	} else {
		push(it);
		int m = (l + r) >> 1;

		if (rm <= m) {
			go((it << 1), l, m, lm, rm);
		} else if (lm > m) {
			go((it << 1) + 1, m + 1, r, lm, rm);
		} else {
			go((it << 1), l, m, lm, m);
			go((it << 1) + 1, m + 1, r, m + 1, rm);
		}
	}
}

int main() {
	int n;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		v[i] %= m;
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(1, -1);

	for (int i = 1; i <= n; i++) {
		x[tin[i]] = v[i];
	}

	build(1, 0, n - 1);

	int q;

	scanf("%d", &q);

	for (int i = 2; i < m; i++) {
		if (prime(i)) {
			pr[i] = 1;
		}
	}

	for (int i = 0; i < q; i++) {
		int c, x, y;

		scanf("%d %d", &c, &x);

		if (c == 1) {
			scanf("%d", &y);

			if (y % m != 0) {
				change(1, 0, n - 1, tin[x], tout[x], y % m);
			}
		} else {
			ans = 0;

			go(1, 0, n - 1, tin[x], tout[x]);

			printf("%d\n", (ans & pr).count());
		}
	}

	return 0;
}