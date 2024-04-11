#include <stdio.h>

#define N   200000
#define M   8 * N

long long aa[N], vv[M], pp[M], pv[M];

void pull(int i) {
	int ii = ((vv[i << 1 | 0] < vv[i << 1 | 1] || (vv[i << 1 | 0] == vv[i << 1 | 1] && pp[i << 1 | 0] > pp[i << 1 | 1])) ? i << 1 | 0 : i << 1 | 1);
	vv[i] = vv[ii], pp[i] = pp[ii];
}

void push(int i) {
	vv[i << 1 | 0] += pv[i];
	vv[i << 1 | 1] += pv[i];
	pv[i << 1 | 0] += pv[i];
	pv[i << 1 | 1] += pv[i];
	pv[i] = 0;
}

void build(int i, int l, int r) {
	if (l == r) {
		vv[i] = aa[l];
		pp[i] = l;
	} else {
		int m = (l + r) / 2;
		build(i << 1 | 0, l, m);
		build(i << 1 | 1, m + 1, r);
		pull(i);
	}
}

void update(int i, int l, int r, int tl, int tr, long long v) {
	if (tl <= l && r <= tr) {
		vv[i] += v, pv[i] += v, push(i);
	} else {
		push(i);
		int m = (l + r) / 2;
		if (tr <= m) update(i << 1 | 0, l, m, tl, tr, v);
		else if (tl > m) update(i << 1 | 1, m + 1, r, tl, tr, v);
		else {
			update(i << 1 | 0, l, m, tl, tr, v);
			update(i << 1 | 1, m + 1, r, tl, tr, v);
		}
		pull(i);
	}
}

int main() {
	static int p[N];
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", &aa[i]);
	build(1, 0, n - 1);
	for (i = 0; i < n; i++) {
		int i_ = pp[1];

		p[i_] = i, update(1, 0, n - 1, i_, n - 1, -(i + 1)), update(1, 0, n - 1, i_, i_, 0x3f3f3f3f3f3f3f3f);
	}
	for (i = 0; i < n; i++)
		printf("%d ", p[i] + 1);
}