#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010; 
int n, m, ret, b[maxn * 2], tree[maxn * 2], ans[maxn];
struct seg {
	int l, r, id;
} a[maxn];
bool operator<(const seg& lhs, const seg& rhs) {
	return lhs.r < rhs.r;
}
int query(int x) {
	x = m - x + 1;
	int ret = 0;
	while (x) {
		ret += tree[x];
		x -= x & (-x);
	}
	return ret;
}
void modify(int x) {
	x = m - x + 1;
	while (x <= m) {
		++tree[x];
		x += x & (-x);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i].l, &a[i].r);
		b[++m] = a[i].l;
		b[++m] = a[i].r;	
		a[i].id = i;	
	}
	sort(b + 1, b + m + 1);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i].l = lower_bound(b + 1, b + m + 1, a[i].l) - b,
		a[i].r = lower_bound(b + 1, b + m + 1, a[i].r) - b;
		
		ans[a[i].id] = query(a[i].l + 1);
		modify(a[i].l);
	}
	
	for (int i = 1; i <= n; ++i)
		printf("%d\n", ans[i]);
}