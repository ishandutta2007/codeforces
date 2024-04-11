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

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

const int maxn = (int)1e6 + 10;

pair <pii, pii> v[maxn];
int p[maxn];
int d[maxn];
int cl[maxn];

int getparent(int x) {
	if (x == p[x]) {
		return x;
	}

	int f = getparent(p[x]);

	d[x] ^= d[p[x]];

	p[x] = f;

	return f;
}

void make(int a, int b, int f) {
	if (cl[a] == cl[b]) {
		cl[a]++;
	}

	p[b] = a;
	d[b] = f;
}

bool add(int x, int y) {
	int px = getparent(x);
	int py = getparent(y);

	if (px == py) {
		return d[x] == d[y];
	}

	if (cl[px] < cl[py]) {
		make(py, px, d[x] ^ d[y] ^ 1);
	} else {
		make(px, py, d[x] ^ d[y] ^ 1);
	}

	return false;
}

int main() {
	int n, m, q;

	scanf("%d %d %d", &n, &m, &q);

	for (int i = 1; i <= m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);

		v[i] = mp(mp(w, i), mp(x, y));
	}

	sort(v + 1, v + m + 1);
	reverse(v + 1, v + m + 1);

	while (q--) {
		int l, r;

		scanf("%d %d", &l, &r);

		for (int i = 1; i <= n; i++) {
			p[i] = i;
			d[i] = 0;
			cl[i] = 1;
		}

		int ans = -1;

		for (int i = 1; i <= m; i++) {
			if (l <= v[i].first.second && v[i].first.second <= r) {
				if (add(v[i].second.first, v[i].second.second)) {
					ans = v[i].first.first;
					break;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}