#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 100010;
int n, m, st, ed, mod, pos, value;
int a[maxn];
struct node {
	ll max, sum;
} seg[maxn * 4];
void update(int tot) {
	seg[tot].sum = seg[tot * 2].sum + seg[tot * 2 + 1].sum;
	seg[tot].max = max(seg[tot * 2].max, seg[tot * 2 + 1].max);
}
void build(int tot, int l, int r) {
	if (l == r) {
		seg[tot].max = seg[tot].sum = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(tot * 2, l, mid);
	build(tot * 2 + 1, mid + 1, r);
	update(tot);
}
void modify(int tot, int l, int r) {
	if (seg[tot].max < mod) return;
	if (l == r) {
		seg[tot].max = seg[tot].sum = seg[tot].max % mod;
		return;
	}
	int mid = (l + r) / 2;
	if (st <= mid) modify(tot * 2, l, mid);
	if (mid < ed) modify(tot * 2 + 1, mid + 1, r);
	update(tot);
}
void modify2(int tot, int l, int r) {
	if (l == r) {
		seg[tot].max = seg[tot].sum = value;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid) modify2(tot * 2, l, mid);
	if (mid < pos) modify2(tot * 2 + 1, mid + 1, r);
	update(tot);
}
ll query(int tot, int l, int r) {
	if (st <= l && r <= ed) return seg[tot].sum;
	int mid = (l + r) / 2; ll ret = 0;
	if (st <= mid) ret += query(tot * 2, l, mid);
	if (mid < ed) ret += query(tot * 2 + 1, mid + 1, r);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	build(1, 1, n);
	
	for (int i = 1; i <= m; ++i) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d%d", &st, &ed);
			printf("%I64d\n", query(1, 1, n));
		}
		if (type == 2) {
			scanf("%d%d%d", &st, &ed, &mod);
			modify(1, 1, n);
		}
		if (type == 3) {
			scanf("%d%d", &pos, &value);
			modify2(1, 1, n);
		}
	}
}