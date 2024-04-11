#include <cstdio>
#include <algorithm>
#include <utility>

const int LG = 30;
const int N = 100000;
int n, m, q, a[N], b[N], c[N], qa[N], qb[N], ans[N];

struct dsu {
	dsu *p;
	int size;
	bool ok;
	void reset() {
		ok = 0;
		p = 0;
		size = 1;
	}
	dsu *find() {
		if (p) return p = p->find();
		return this;
	}
} d[N];

void merge(dsu *a, dsu *b) {
	a = a->find();
	b = b->find();
	if (a != b) {
		if (a->size < b->size) std::swap(a, b);
		b->p = a;
		a->size += b->size;
	}
}

bool same(dsu *a, dsu *b) {
	return a->find() == b->find();
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", a + i, b + i, c + i);
		--a[i];
		--b[i];
	}
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", qa + i, qb + i);
		--qa[i];
		--qb[i];
		ans[i] = 2;
	}
	for (int i = 0; i < LG; ++i) {
		for (int j = 0; j < n; ++j) d[j].reset();
		for (int j = 0; j < m; ++j) if (c[j] >> i & 1) merge(d + a[j], d + b[j]);
		for (int j = 0; j < q; ++j) if (same(d + qa[j], d + qb[j])) ans[j] = 0;
	}
	for (int i = 1; i < LG; ++i) {
		for (int j = 0; j < n; ++j) d[j].reset();
		for (int j = 0; j < m; ++j) if (c[j] >> i & 1 && c[j] & 1) merge(d + a[j], d + b[j]);
		for (int j = 0; j < m; ++j) if (c[j] & 1 ^ 1) d[a[j]].find()->ok = d[b[j]].find()->ok = 1;
		for (int j = 0; j < q; ++j) if (d[qa[j]].find()->ok) ans[j] = std::min(ans[j], 1);
	}
	for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
	return 0;
}