#include <bits/stdc++.h> 
using namespace std;

const int M = 1e9 + 7;
const int MX = 1e5 + 1; 

int par[MX], heavy[MX], dep[MX], len[MX], rt[MX], ndx[MX], inv[MX], st[MX * 4], la[MX * 4], n;
vector<int> adj[MX];

int add(int a, int b) {
	int res = a + b;
	return res < M ? res : res - M;
}

int sub(int a, int b) {
	int res = a - b;
	return res < 0 ? res + M : res;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int dfs(int u) {
	int sz = 1, mx = 0;
	for (auto c : adj[u]) {
		if (c == par[u])
			continue;
		par[c] = u;
		dep[c] = dep[u] + 1;
		int chd = dfs(c);
		if (chd > mx) {
			heavy[u] = c;
			mx = chd;
		}
		sz += chd;
	}
	return sz;
}

template <class F>
void pathop(int u, int v, F f) {
	for ( ; rt[u] != rt[v]; v = par[rt[v]]) {
		if (dep[u] > dep[v]) {
			swap(u, v);
		}
		f(ndx[rt[v]], ndx[v]);
	}
	if (dep[u] > dep[v]) {
		swap(u, v);
	}
	f(ndx[u], ndx[v]);
}

void push(int v, int l, int m, int r) {
	st[v * 2] = add(st[v * 2], mul(la[v], m - l + 1));
	la[v * 2] = add(la[v * 2], la[v]);
	st[v * 2 + 1] = add(st[v * 2 + 1], mul(la[v], r - m));
	la[v * 2 + 1] = add(la[v * 2 + 1], la[v]);
	la[v] = 0;
}

void updst(int a, int b, int val, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		st[v] = add(st[v], mul(val, r - l + 1));
		la[v] = add(la[v], val);
	} else {
		int m = (l + r) / 2;
		push(v, l, m, r);
		updst(a, b, val, v * 2, l, m);
		updst(a, b, val, v * 2 + 1, m + 1, r);
		st[v] = add(st[v * 2], st[v * 2 + 1]);
	}
}

int qryst(int a, int b, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return 0;
	if (a <= l && r <= b)
		return st[v];
	int m = (l + r) / 2;
	push(v, l, m, r);
	return add(qryst(a, b, v * 2, l, m), qryst(a, b, v * 2 + 1, m + 1, r));
}

void upd(int u, int v, int val) {
	pathop(u, v, [&](int a, int b) {
		updst(a, b, val);
	});
}

int qry(int u, int v) {
	int res = 0;
	pathop(u, v, [&](int a, int b) {
		res = add(res, qryst(a, b));
	});
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<tuple<int, int, int>> pt;
	for (int i = 1; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		len[i] = r - l + 1;
		pt.emplace_back(l, 1, i);
		pt.emplace_back(r + 1, 0, i);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (heavy[par[i]] != i) {
			for (int j = i; j; j = heavy[j]) {
				ndx[j] = cnt++;
				rt[j] = i;
			}
		}
	}

	inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		inv[i] = sub(M, mul(M / i, inv[M % i]));
	}

	sort(pt.begin(), pt.end());
	int cur = 0, ans = 0, sumdep = 0, suminv = 0, sumexc = 0, sumlca = 0;
	for (int i = 1; i < MX; ++i) {
		while (cur < (int)pt.size() && get<0>(pt[cur]) == i) {
			auto [c, t, x] = pt[cur++];
			int y = mul(dep[x], inv[len[x]]);
			if (t) {
				sumdep = add(sumdep, y);
				suminv = add(suminv, inv[len[x]]);
				sumexc = add(sumexc, mul(inv[len[x]], y));
				sumlca = add(sumlca, mul(sub(qry(1, x), qry(1, 1)), inv[len[x]]));
				upd(1, x, inv[len[x]]);
			} else {
				upd(1, x, M - inv[len[x]]);
				sumdep = sub(sumdep, y);
				suminv = sub(suminv, inv[len[x]]);
				sumexc = sub(sumexc, mul(inv[len[x]], y));
				sumlca = sub(sumlca, mul(sub(qry(1, x), qry(1, 1)), inv[len[x]]));
			}
		}
		ans = add(ans, sub(sub(mul(sumdep, suminv), sumexc), add(sumlca, sumlca)));
	}

	for (int i = 1; i <= n; ++i) {
		ans = mul(ans, len[i]);
	}
	cout << ans << '\n';
}