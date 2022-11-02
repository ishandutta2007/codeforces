#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <list>
using namespace std;

#define N 210000
#define P 1000000007
int n, q, a[N], w[N];
long long W[N], AW[N];

void modify(long long *b, int x, long long y) {
	for (; x <= n; x += x & -x)
		b[x] += y;
}

long long query(long long *b, int x) {
	long long ans = 0;
	for (; x; x -= x & -x)
		ans += b[x];
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] -= i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		modify(W, i, w[i]);
		modify(AW, i, 1LL * a[i] * w[i] % P);
	}
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < 0) {
			x = -x;
			modify(W, x, -w[x]);
			modify(AW, x, -(1LL * a[x] * w[x] % P));
			w[x] = y;
			modify(W, x, w[x]);
			modify(AW, x, (1LL * a[x] * w[x] % P));
		}else {
			long long base = query(W, x - 1);
			long long SW = query(W, y) - base;
			int l = x - 1, r = y, mid;
			while (l < r - 1) {
				mid = (l + r) / 2;
				if (query(W, mid) - base >= (SW + 1) / 2)
					r = mid;
				else
					l = mid;
			}
			long long ans = 0;
			if (x < r) {
				ans += 1LL * a[r] * ((query(W, r - 1) - query(W, x - 1)) % P) % P;
				ans -= (query(AW, r - 1) - query(AW, x - 1)) % P;
			}
			if (r < y) {
				ans -= 1LL * a[r] * ((query(W, y) - query(W, r)) % P) % P;
				ans += (query(AW, y) - query(AW, r)) % P;
			}
			ans = ((ans % P) + P) % P;
			printf("%I64d\n", ans);
		}
	}
}