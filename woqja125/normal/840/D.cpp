#include<stdio.h>
struct seg {
	seg *l, *r;
	int s;
	seg();
} nodes[10000000];
seg nseg;
seg::seg() {
	l = r = &nseg;
}
seg* pt[300001];
int C = -1;
void add(const seg* o, seg* &t, int x, int s, int e) {
	if (t == &nseg) t = ++C + nodes;
	t->s = o->s + 1;
	if (s == e) return;
	int m = (s + e) / 2;
	if (x <= m) {
		t->r = o->r;
		add(o->l, t->l, x, s, m);
	}
	else {
		t->l = o->l;
		add(o->r, t->r, x, m + 1, e);
	}
}
int find(const seg *a, const seg *b, int s, int e, int k) {
	if (s == e) return s;
	int m = (s + e) / 2;
	if (b->l->s - a->l->s >= k) {
		int r = find(a->l, b->l, s, m, k);
		if (r != -1) return r;
	}
	if (b->r->s - a->r->s >= k) {
		int r = find(a->r, b->r, m + 1, e, k);
		if (r != -1) return r;
	}
	return -1;
}
int main() {
	int n, q, t, l, r;
	scanf("%d%d", &n, &q);
	for (int i = 0; i <= n; i++) pt[i] = &nseg;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		add(pt[i-1], pt[i], t, 1, n);
	}
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d", &l, &r, &t);
		printf("%d\n", find(pt[l - 1], pt[r], 1, n, (r - l + 1) / t + 1));
	}
	return 0;
}