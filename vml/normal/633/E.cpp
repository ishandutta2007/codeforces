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

const int maxn = (int)1e6 + 10;
int v[maxn];
int c[maxn];

int trr[4 * maxn];
int tr2[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		trr[it] = v[l];
		tr2[it] = c[l];
	} else {
		int m = (l + r) >> 1;

		build((it << 1), l, m);
		build((it << 1) + 1, m + 1, r);

		trr[it] = max(trr[2 * it], trr[2 * it + 1]);
		tr2[it] = min(tr2[2 * it], tr2[2 * it + 1]);
	}
}

pii go(int it, int l, int r, int lm, int rm) {
	if (l == lm && r == rm) {
		return mp(trr[it], tr2[it]);
	} else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm);
		} else {
			pii a = go(2 * it, l, m, lm, m);
			pii b = go(2 * it + 1, m + 1, r, m + 1, rm);

			return mp(max(a.first, b.first), min(a.second, b.second));
		}
	}
}

int search(int it, int l, int r, int lm, int rm, int a, int b) {
	if (l == lm && r == rm) {
		if (l == r) {
			if (max(trr[it], a) <= min(tr2[it], b)) {
				return l;
			} else {
				return l - 1;
			}
		}

		int m = (l + r) >> 1;

		if (trr[2 * it] <= tr2[2 * it]) {
			return search(2 * it + 1, m + 1, r, m + 1, rm, max(a, trr[2 * it]), min(b, tr2[2 * it]));
		} else {
			return search(2 * it, l, m, lm, m, a, b);
		}
	} else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return search(2 * it, l, m, lm, rm, a, b);
		} else if (lm > m) {
			return search(2 * it + 1, m + 1, r, lm, rm, a, b);
		} else {
			int x = search(2 * it, l, m, lm, m, a, b);
			pair <int, int> f = go(2 * it, l, m, lm, m);
			a = max(a, f.first);
			b = min(b, f.second);

			if (x == m) {
				return search(2 * it + 1, m + 1, r, m + 1, rm, a, b);
			}

			return x;
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i] *= 100;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}

	build(1, 0, n - 1);

	for (int i = 0; i < n; i++) {
		int pos = search(1, 0, n - 1, i, n - 1, 0, (int)1e9);

		if (pos >= i) {
			pii f = go(1, 0, n - 1, i, pos);
			v[i] = min(f.first, f.second);

			if (pos != n - 1) {
				f.first = max(f.first, v[pos + 1]);
				f.second = min(f.second, c[pos + 1]);

				v[i] = max(v[i], min(f.first, f.second));
			}
		} else {
			v[i] = min(v[i], c[i]);
		}
	}

	sort(v, v + n);

	ld now = (ld)k / n;

	ld ans = 0;

	for (int i = 0; i <= n - k; i++) {
		ans += now * v[i];

		now *= (n - k - i);
		now /= (n - i - 1);
	}

	printf("%.10lf", (double)ans);

	return 0;
}