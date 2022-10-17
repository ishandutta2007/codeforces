#include <cstdio>
#include <algorithm>

struct item {
	long long mn, mx;
	item(long long x, long long y) {
		mn = x;
		mx = y;
	}
	item(long long x) {
		mn = mx = x;
	}
	item() {
		mn = ~((long long)1 << 63);
		mx = (long long)1 << 63;
	}
	item operator+(item arg) {
		return item(std::min(mn, arg.mn), std::max(mx, arg.mx));
	}
};

const int N = 100000;
int n, q;
long long a[N];
item t[N << 2];

void build(int v = 0, int tl = 0, int tr = n) 
{
	if (tr - tl == 1) t[v] = item(a[tl]);
	else {
		int m = tl + tr >> 1;
		build((v << 1) + 1, tl, m);
		build((v << 1) + 2, m, tr);
		t[v] = t[(v << 1) + 1] + t[(v << 1) + 2];
	}
}

item query(int l, int r, int v = 0, int tl = 0, int tr = n) 
{
	if (tl >= r || tr <= l) return item();
	if (tl >= l && tr <= r) return t[v];
	int m = tl + tr >> 1;
	return query(l, r, (v << 1) + 1, tl, m) + query(l, r, (v << 1) + 2, m, tr);
}

int main() 
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) scanf("%lld", a + i);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a[i] -= x;
		if (i) a[i] += a[i - 1];
	}
	build();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		item ans = query(l, r);
		long long dec = l ? a[l - 1] : 0;
		if (!(ans.mx - dec) && !(a[r - 1] - dec)) printf("%lld\n", dec - ans.mn);
		else printf("-1\n");
	}
	return 0;
}