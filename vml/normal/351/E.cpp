#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

#define lld I64d

const int maxn = 2010;
int v[maxn];
int tree[4 * maxn];

void build(int l, int r, int it) {
	if (l == r) {
		tree[it] = 1;
	} else {
		int m = (l + r) / 2;
		build(l, m, 2 * it);
		build(m + 1, r, 2 * it + 1);
		tree[it] = tree[2 * it] + tree[2 * it + 1];
	}
}

int search(int l, int r, int lm, int rm, int it) {
	if (l == lm && r == rm) {
		return tree[it];
	} else {
		int m = (l + r) / 2;
		if (rm <= m) {
			return search(l, m, lm, rm, 2 * it);
		} else if (lm > m) {
			return search(m + 1, r, lm, rm, 2 * it + 1);
		} else {
			return search(l, m, lm, m, 2 * it) + search(m + 1, r, m + 1, rm, 2 * it + 1);
		}
	}
}

void change(int l, int r, int x, int it) {
	if (l == r) {
		tree[it] = 0;
	} else {
		int m = (l + r) / 2;
		if (x <= m) {
			change(l, m, x, 2 * it);
		} else {
			change(m + 1, r, x, 2 * it + 1);
		}
		tree[it] = tree[2 * it] + tree[2 * it + 1];
	}
}

int main() {
#ifdef ONLINE_JUDGE
    //freopen("circuit.in", "r", stdin);
    //freopen("circuit.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		v[i] = abs(v[i]);
	}
	int ans = 0;
	build(1, n, 1);
	for (int i = 0; i < n; i++) {
		int numb = 1;
		int go = 0;
		for (int j = 2; j <= n; j++) {
			if (v[j] > v[numb]) {
				numb = j;
				go = 0;
			} else if (v[j] == v[numb]) {
				go++;
			}
		}
		v[numb] = -1;
		change(1, n, numb, 1);
		int l, r;
		l = search(1, n, 1, numb, 1);
		r = search(1, n, numb, n, 1) - go;
		ans += min(l, r);
	}
	printf("%d", ans);
	return 0;
}