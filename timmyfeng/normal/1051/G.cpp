#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 5;
const int MXST = MX * 19;

int par[MX], mn[MX], sz[MX], chd[MXST][2], rt[MX], mat[2 * MX], alc, n;
ll st_sum[MXST], st_cnt[MXST], delt1, delt2, ans;

int bld(int a, int l = 1, int r = n) {
	int v = ++alc;
	st_cnt[v] = 1;
	st_sum[v] = a;
	if (l == r)
		return v;
	int m = (l + r) / 2;
	if (a <= m) {
		chd[v][0] = bld(a, l, m);
	} else {
		chd[v][1] = bld(a, m + 1, r);
	}
	return v;
}

int merge(int a, int b) {
	if (!a && !b) {
		return 0;
	} else if (!b) {
		ans += delt2 * st_sum[a];
		delt1 += st_cnt[a];
		return a;
	} else if (!a) {
		ans += delt1 * st_sum[b];
		delt2 += st_cnt[b];
		return b;
	}
	chd[a][1] = merge(chd[a][1], chd[b][1]);
	chd[a][0] = merge(chd[a][0], chd[b][0]);
	st_sum[a] = st_sum[chd[a][0]] + st_sum[chd[a][1]];
	st_cnt[a] = st_cnt[chd[a][0]] + st_cnt[chd[a][1]];
	return a;
}

int find(int a) {
	if (par[a] != a) {
		par[a] = find(par[a]);
	}
	return par[a];
}

void unite(int a, int b) {
	if (a == b)
		return;
	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	par[a] = b;
	sz[b] += sz[a];
	mn[b] = min(mn[b], mn[a]);
}

void combine(int a, int b) {
	ans -= (mn[b] - mn[a]) * st_sum[rt[b]];
	unite(a, b);
	delt1 = delt2 = 0;
	rt[find(a)] = merge(rt[a], rt[b]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	iota(par, par + MX, 0);
	fill(sz, sz + MX, 1);

	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;

		rt[b] = bld(b);
		mn[b] = a;
		if (mat[a]) {
			combine(find(mat[a]), b);
		} else if (mat[a - 1]) {
			combine(find(mat[a - 1]), b);
		}

		int u = find(b);
		a = mn[u] + sz[u] - 1;
		mat[a] = b;
		if (mat[a + 1]) {
			combine(u, find(mat[a + 1]));
		}
		cout << ans << '\n';
	}
}