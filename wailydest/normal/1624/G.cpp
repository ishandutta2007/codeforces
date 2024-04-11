#include <cstdio>
#include <utility>

const int N = 200000;
int t, n, m, a[N], b[N], c[N];

struct dsu {
	dsu *p;
	int size;
	dsu *find() {
		if (p) return p = p->find();
		return this;
	}
} d[N];

bool merge(dsu *a, dsu *b) 
{
	a = a->find();
	b = b->find();
	if (a == b) return 0;
	if (a->size < b->size) std::swap(a, b);
	b->p = a;
	a->size += b->size;
	return 1;
}

bool test(int x, int l) 
{
	int amt = n - 1;
	for (int i = 0; i < n; ++i) {
		d[i].p = 0;
		d[i].size = 1;
	}
	for (int i = 0; i < m; ++i) if (((c[i] | x) >> l) == (x >> l)) amt -= merge(d + a[i], d + b[i]);
	return !amt;
}

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", a + i, b + i, c + i);
			--a[i];
			--b[i];
		}
		int ans = 0;
		for (int i = 30; i >= 0; --i) if (!test(ans, i)) ans |= 1 << i;
		printf("%d\n", ans);
	}
	return 0;
}