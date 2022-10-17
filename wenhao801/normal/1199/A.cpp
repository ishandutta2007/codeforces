#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
const ll INF = LLONG_MAX;

int N, M;
ll Max[MAXN << 2] = {};
ll Min[MAXN << 2] = {};
ll lazy[MAXN << 2] = {};

void pushUp (int root) {
	Max[root] = max(Max[root << 1], Max[root << 1 | 1]);
	Min[root] = min(Min[root << 1], Min[root << 1 | 1]);
	return;
}

void build (int root, int l, int r) {
	if (l == r) {
		Max[root] = read();
		Min[root] = Max[root];
		return;
	}
	ll mid = (l + r) >> 1;
	build(root << 1, l, mid);
	build(root << 1 | 1, mid + 1, r);
	pushUp(root);
	return;
}

void getlazy (int l, int r, int num, ll k) {
	lazy[num] = (lazy[num] + k);
	Max[num] = (Max[num] + k);
	Min[num] = (Min[num] + k);
}

void pushDown (int l, int r, int num) {
	ll mid = (l + r) >> 1;
	getlazy(l, mid, num << 1, lazy[num]);
	getlazy(mid + 1, r, num << 1 | 1, lazy[num]);
	lazy[num] = 0;
	return;
}

ll getMax(int l, int r, int L, int R, int num) {
	if (l <= L && R <= r)
		return Max[num];
	ll mid = (L + R) >> 1;
	pushDown(L, R, num);
	ll ret = -INF;
	if (l <= mid)
		ret = max(ret, getMax(l, r, L, mid, num << 1));
	if (r > mid)
		ret = max(ret, getMax(l, r, mid + 1, R, num << 1 | 1));
	return ret;
}

ll getMin(int l, int r, int L, int R, int num) {
	if (l > r) return (1e9 + 7);
	if (l <= L && R <= r)
		return Min[num];
	ll mid = (L + R) >> 1;
	pushDown(L, R, num);
	ll ret = INF;
	if (l <= mid)
		ret = min(ret, getMin(l, r, L, mid, num << 1));
	if (r > mid)
		ret = min(ret, getMin(l, r, mid + 1, R, num << 1 | 1));
	return ret;
}

int max (int x, int y) { return x > y ? x : y; }
int min (int x, int y) { return x < y ? x : y; }

int main () {
	N = read();
	int x = read(), y = read();
	int i, j;
	build(1, 1, N);
	for (i = 1; i <= N; i++) {
		int k = getMin(i, i, 1, N, 1);
		if (k < getMin(max(1, i - x), i - 1, 1, N, 1) && k < getMin(i + 1, min(i + y, N), 1, N, 1)) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}