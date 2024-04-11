#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <set>
#include <cstdlib>
#include <memory.h>
#include <cassert>
#include <queue>
#include <unordered_map>
#include <ctime>

using namespace std;

const int maxn = 110;

int x[maxn];
int d[maxn];

struct point {
	int a, b, c, d;

	point(): a(0), b(0), c(0), d(0) {

	}

	point(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {

	}
};

bool operator <(point x, point y) {
	if (x.a != y.a) {
		return x.a < y.a;
	}

	if (x.b != y.b) {
		return x.b < y.b;
	}

	if (x.c != y.c) {
		return x.c < y.c;
	}

	return x.d < y.d;
}

map <point, int> dp;

int check(int bl, int br, int lc, int rc) {
	br = min(br, rc);
	bl = max(bl, lc);

	return max(0, br - bl);
}

int go(int l, int r, int lc, int rc) {
	if (l > r) {
		return 0;
	}

	point f = point(l, r, lc, rc);

	if (!dp.count(f)) {
		int ans = 0;

		int pos = l;

		for (int i = l + 1; i <= r; i++) {
			if (d[pos] < d[i]) {
				pos = i;
			}
		}

		int bl = x[pos];
		int pl = pos;
		int br = x[pos] + d[pos];
		int pr = pos;

		int w = r + 1;

		for (int i = pos + 1; i <= r; i++) {
			if (x[i] > x[pos] + d[pos]) {
				w = i;
				break;
			}

			if (x[i] - d[i] < bl) {
				bl = x[i] - d[i];
				pl = i;
			}

			if (x[i] + d[i] > br) {
				br = x[i] + d[i];
				pr = i;
			}
		}

		if (pl != pr || (pl == pr && pl == pos)) {
			ans = go(l, pos - 1, lc, min(bl, rc)) + go(w, r, max(br, lc), rc) + check(bl, br, lc, rc);
		} else {
			int nbl = x[pos];
			int npl = pos;

			for (int i = pos + 1; i < w; i++) {
				if (x[i] - d[i] < nbl && i != pr) {
					nbl = x[i] - d[i];
					npl = i;
				}
			}

			ans = go(l, pos - 1, lc, min(nbl, rc)) + go(w, r, max(br, lc), rc) + check(nbl, br, lc, rc);

			int nbr = x[pos] + d[pos];
			int npr = pos;

			for (int i = pos + 1; i < w; i++) {
				if (x[i] + d[i] > nbr && i != pl) {
					nbr = x[i] + d[i];
					npr = i;
				}
			}

			ans = max(ans, go(l, pos - 1, lc, min(bl, rc)) + go(w, r, max(nbr, lc), rc) + check(bl, nbr, lc, rc));
		}

		w = l - 1;

		bl = x[pos] - d[pos];
		pl = pos;
		br = x[pos];
		pr = pos;

		for (int i = pos - 1; i >= l; i--) {
			if (x[i] < x[pos] - d[pos]) {
				w = i;
				break;
			}

			if (x[i] - d[i] < bl) {
				bl = x[i] - d[i];
				pl = i;
			}

			if (x[i] + d[i] > br) {
				br = x[i] + d[i];
				pr = i;
			}
		}

		if (pl != pr || (pl == pr && pl == pos)) {
			ans = max(ans, go(l, w, lc, min(bl, rc)) + go(pos + 1, r, max(br, lc), rc) + check(bl, br, lc, rc));
		} else {
			int nbl = x[pos] - d[pos];
			int npl = pos;

			for (int i = w + 1; i < pos; i++) {
				if (x[i] - d[i] < nbl && i != pr) {
					nbl = x[i] - d[i];
					npl = i;
				}
			}

			ans = max(ans, go(l, w, lc, min(nbl, rc)) + go(pos + 1, r, max(br, lc), rc) + check(nbl, br, lc, rc));

			int nbr = x[pos];
			int npr = pos;

			for (int i = w + 1; i < pos; i++) {
				if (x[i] + d[i] > nbr && i != pl) {
					nbr = x[i] + d[i];
					npr = i;
				}
			}

			ans = max(ans, go(l, w, lc, min(bl, rc)) + go(pos + 1, r, max(nbr, lc), rc) + check(bl, nbr, lc, rc));
		}

		dp[f] = ans;
	}

	return dp[f];
}

pair <int, int> g[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> d[i];
		g[i] = make_pair(x[i], d[i]);
	}

	sort(g, g + n);

	for (int i = 0; i < n; i++) {
		x[i] = g[i].first;
		d[i] = g[i].second;
	}

	cout << go(0, n - 1, -(int)1e9, (int)1e9) << endl;

	return 0;
}