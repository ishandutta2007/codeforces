#include <bits/stdc++.h>

const int N = 200000;

struct sgt{
	#define lch (x << 1)
	#define rch (x << 1 | 1)

	static const int S = (N << 1);

	int tg[S + 5], mn[S + 5], mx[S + 5], le[S + 5], ri[S + 5];
	void addtag(int x, int k) {
		tg[x] += k, mn[x] += k, mx[x] += k;
	}
	void pushup(int x) {
		mn[x] = std::min(mn[lch], mn[rch]);
		mx[x] = std::max(mx[lch], mx[rch]);
	}
	void pushdown(int x) {
		if (tg[x]) {
			addtag(lch, tg[x]), addtag(rch, tg[x]);
			tg[x] = 0;
		}
	}
	void build(int x, int l, int r) {
		le[x] = l, ri[x] = r, tg[x] = mn[x] = mx[x] = 0;
		if (l == r) return;
		int m = (l + r) >> 1;
		build(lch, l, m), build(rch, m + 1, r);
	}
	void add(int x, int p, int k) {
		if (p > ri[x]) return;

		if (le[x] == ri[x]) {addtag(x, k); return;}
		int m = (le[x] + ri[x]) >> 1; pushdown(x);
		if (p <= m) add(lch, p, k), addtag(rch, k);
		else add(rch, p, k);
		pushup(x);
	}
	int query_mn(int x, int l, int r) {
		if (l <= le[x] && ri[x] <= r) return mn[x];
		if (l > ri[x] || r < le[x]) return int(1E9);
		pushdown(x);
		return std::min(query_mn(lch, l, r), query_mn(rch, l, r));
	}
	int query_mx(int x, int l, int r) {
		if (l <= le[x] && ri[x] <= r) return mx[x];
		if (l > ri[x] || r < le[x]) return -int(1E9);
		pushdown(x);
		return std::max(query_mx(lch, l, r), query_mx(rch, l, r));		
	}
}To, Te;

int ans[N + 5];
std::vector<int>v[N + 5];
int main() {
	int n; scanf("%d", &n);
	for (int i = 1, x; i <= n; i++)
		scanf("%d", &x), v[x].push_back(i);
	
	To.build(1, 0, (n - 1) >> 1), Te.build(1, 0, n >> 1);
	for (int i = 1; i <= n; i++)
		To.add(1, i >> 1, 1), Te.add(1, (i + 1) >> 1, 1);
	for (int i = 1; i <= n; i++) {
		for (auto x : v[i]) {
			int ox = To.query_mx(1, x >> 1, (n - 1) >> 1);
			int on = To.query_mn(1, 0, (x >> 1) - 1);
			int ex = Te.query_mx(1, (x + 1) >> 1, n >> 1);
			int en = Te.query_mn(1, 0, (x - 1) >> 1);

			ans[x] = std::max(std::max((ex - en) >> 1, (ox - on) >> 1),
				std::max((ex - on - 1) >> 1, (ox - en - 1) >> 1));
		}
		for (auto x : v[i])
			To.add(1, x >> 1, -2), Te.add(1, (x + 1) >> 1, -2);
		for (auto x : v[i]) {
			int on = To.query_mn(1, x >> 1, (n - 1) >> 1);
			int ox = To.query_mx(1, 0, (x >> 1) - 1);
			int en = Te.query_mn(1, (x + 1) >> 1, n >> 1);
			int ex = Te.query_mx(1, 0, (x - 1) >> 1);

			ans[x] = std::max(ans[x],
				std::max(std::max((ex - en) >> 1, (ox - on) >> 1) - 1,
				std::max((ex - on - 1) >> 1, (ox - en - 1) >> 1)));
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
}