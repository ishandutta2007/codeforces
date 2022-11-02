#include <bits/stdc++.h>

const int N = 50000;
const int M = 100000;

int ch[2][250*M + 5], mn[250*M + 5], ncnt;
void insert(int &x, const int &l, const int &r, const int &p, const int &k) {
	if (!x) x = (++ncnt), mn[x] = mn[0]; mn[x] = std::min(mn[x], k);
	if (l == r) return;

	int m = (l + r) >> 1;
	if (p <= m) insert(ch[0][x], l, m, p, k);
	else insert(ch[1][x], m + 1, r, p, k);
}
int query(const int &x, const int &l, const int &r, const int &p) {
	if (!x || l == r) return mn[x];

	int m = (l + r) >> 1;
	if (p <= m) return std::min(query(ch[0][x], l, m, p), mn[ch[1][x]]);
	else return query(ch[1][x], m + 1, r, p);
}

int rt[N + 5], n, m;
void insert(const int &x, int y, const int &i) {
	for (; y <= n; y += (y & -y)) insert(rt[y], 1, n, x, i);
}
int query(const int &x, int y) {
	int r = mn[0];
	for (; y; y ^= (y & -y)) r = std::min(r, query(rt[y], 1, n, x));
	return r;
}

int le[M + 5], ri[M + 5];
int solve(const int &l, const int &r) {
	if (l > r) return 0;
	
	int k = query(l, r);
	if (k <= m) {
		return solve(l, le[k] - 1) + solve(ri[k] + 1, r) + (ri[k] - le[k] + 1);
	} else {
		return 0;
	}
}

int ans[N + 5];
struct seg{int l, r, i;};
std::vector<seg>v[N + 5];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &le[i], &ri[i]);
		v[ri[i] - le[i] + 1].push_back((seg){le[i], ri[i], i});
	}
	
	mn[0] = m + 1;
	for (int i = n; i >= 1; i--) {
		for (auto x : v[i]) insert(x.l, x.r, x.i);
		ans[i] = solve(1, n);
	}
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}