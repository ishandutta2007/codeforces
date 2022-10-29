#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef unsigned int ui;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
const int maxn = 200010;
int n, st, ed, value, maxv, a[maxn];
vector<int> b[maxn], v[maxn];
LL H[maxn];
struct seg {
	int len, minv, tag;
	LL sum;
} seg[maxn * 4];
void prepare() {
	scanf("%d", &n);
	maxv = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		maxv = max(maxv, a[i]);
		v[a[i]].PB(i);
	}
	for (int i = 1; i <= maxv; ++i) {
		for (int j = i; j <= maxv; j += i)
			for (auto k : v[j])
				b[i].PB(k);
	}
	
	for (int i = 1; i <= maxv; ++i)
		sort(b[i].begin(), b[i].end());
}
inline void update(int tot) {
	seg[tot].sum = seg[tot * 2].sum + seg[tot * 2 + 1].sum;
	seg[tot].minv = min(seg[tot * 2].minv, seg[tot * 2 + 1].minv);
}
inline void calc(int tot, int v) {
	seg[tot].minv = seg[tot].tag = v;
	seg[tot].sum = 1LL * seg[tot].len * v;
}
inline void down(int tot) {
	if (seg[tot].tag) {
		calc(tot * 2, seg[tot].tag);
		calc(tot * 2 + 1, seg[tot].tag);
		seg[tot].tag = 0;
	}
}
void build(int tot, int l, int r) {
	seg[tot].len = r - l + 1;
	if (l == r) {
		seg[tot].minv = seg[tot].sum = l;
		return;
	}
	int mid = (l + r) / 2;
	build(tot * 2, l, mid);
	build(tot * 2 + 1, mid + 1, r);
	update(tot);
}
int bound(int tot, int l, int r) {
	if (l == r) {
		return seg[tot].minv < value ? l : 0;
	}
	down(tot);
	int mid = (l + r) / 2;
	if (seg[tot * 2 + 1].minv < value) return bound(tot * 2 + 1, mid + 1, r);
	else return bound(tot * 2, l, mid); 
}
void modify(int tot, int l, int r) {
	if (st <= l && r <= ed) {
		calc(tot, value);
		return;
	}
	down(tot);
	int mid = (l + r) / 2;
	if (st <= mid) modify(tot * 2, l, mid);
	if (mid < ed) modify(tot * 2 + 1, mid + 1, r);
	update(tot);
}
void calc(int l, int r, int v) {
	value = v;
	int p = bound(1, 1, n);
	if (p >= l) {
		st = l; ed = min(p, r);
		modify(1, 1, n);
	}
}
int main() {
	prepare();
	build(1, 1, n);
	
	for (int i = maxv + 1; i >= 1; --i) {
		int k = b[i].size();
		if (k > 1) {
			calc(1, b[i][0], b[i][k - 2]);
			calc(b[i][0] + 1, b[i][1], b[i][k - 1]);
			if (b[i][1] < n) calc(b[i][1] + 1, n, n + 1); 
		}
		H[i] = 1LL * (n + 1) * n - seg[1].sum;
	}
	LL ans = 0;
	for (int i = 1; i <= maxv; ++i) 
		ans += 1LL * (H[i + 1] - H[i]) * i;
	cout << ans << endl;	
	return 0;
}