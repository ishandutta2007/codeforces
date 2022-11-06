#include<stdio.h>
int p[200001];
struct node {
	node *l, *r;
	node();
	int s;
	int gets(int s, int e, int x, int y) {
		if (y < s || e < x) return 0;
		if (x <= s && e <= y) return this->s;
		return l->gets(s, (s + e) / 2, x, y) + r->gets((s + e) / 2 + 1, e, x, y);
	}
} arr[4000000];
node nulln;
node::node() {
	l = r = &nulln;
	s = 0;
}
node* newn() {
	static int C = -1;
	return ++C + arr;
}
node* add(node *o, int s, int e, int x) {
	if (x < s || x > e) return o;
	node* r = newn();
	r->s = o->s + 1;
	if (s == e) return r;
	r->l = add(o->l, s, (s + e) / 2, x);
	r->r = add(o->r, (s + e) / 2 + 1, e, x);
	return r;
}
node *x[200010];
long long getc(int x) {
	return 1ll * x*(x - 1) / 2;
}
int main() {
	int q, n;
	scanf("%d%d", &n, &q);
	x[0] = &nulln;
	for (int i = 1; i <= n; i++) {
		scanf("%d", p + i);
		x[i] = add(x[i - 1], 1, n, p[i]);
	}
	int l, d, r, u;
	for (int i = 1; i <= q; i++) {
		scanf("%d%d%d%d", &l, &d, &r, &u);
		long long ans = 1ll * n*(n - 1) / 2;
		ans -= getc(l - 1); ans -= getc(n - r);
		ans -= getc(d - 1); ans -= getc(n - u);
		ans += getc(x[l - 1]->gets(1, n, 0, d - 1));
		ans += getc(x[l - 1]->gets(1, n, u + 1, n + 1));
		ans += getc(d-1 - x[r]->gets(1, n, 0, d - 1));
		ans += getc(n-u - x[r]->gets(1, n, u + 1, n + 1));
		printf("%lld\n", ans);
	}
	return 0;
}

/*
4 2
1 3 2 4
4 4 4 4 

*/