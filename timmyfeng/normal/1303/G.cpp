#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using pt = pair<ll, ll>;
#define x first
#define y second
const int MX = 1.5e5 + 5;
const int LOG = 20;

ll dot(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

ll ps[MX][LOG], pss[MX][LOG], a[MX], ans;
int sz[MX], len[MX][LOG], dep, tot, n;
vector<int> adj[MX], cdec[MX];
bool vstd[MX], used[4 * MX];
pt lct[4 * MX];

void build(int v = 1, int l = 0, int r = n + 1) {
	if (!used[v])
		return;
	used[v] = false;
	lct[v] = {0, 0};
	if (r - l > 1) {
		int m = (l + r) / 2;
		build(v * 2, l, m);
		build(v * 2 + 1, m, r);
	}
}

void upd(pt ln, int v = 1, int l = 0, int r = n + 1) {
	used[v] = true;
	int m = (l + r) / 2;
	bool mxl = dot(ln, {l, 1}) > dot(lct[v], {l, 1});
	bool mxm = dot(ln, {m, 1}) > dot(lct[v], {m, 1});
	if (mxm) {
		swap(lct[v], ln);
	}
	if (r - l == 1)
		return;
	if (mxl == mxm) {
		upd(ln, v * 2 + 1, m, r);
	} else {
		upd(ln, v * 2, l, m);
	}
}

ll qry(int x, int v = 1, int l = 0, int r = n + 1) {
	ll res = dot(lct[v], {x, 1});
	int m = (l + r) / 2;
	if (r - l == 1)
		return res;
	if (x < m)
		return max(res, qry(x, v * 2, l, m));
	return max(res, qry(x, v * 2 + 1, m, r));
}

void dfssz(int u, int p) {
	sz[u] = 1;
	for (auto c : adj[u]) {
		if (p == c || vstd[c])
			continue;
		dfssz(c, u);
		sz[u] += sz[c];
	}
}

int dfsfind(int u, int p) {
	for (auto c : adj[u]) {
		if (p == c || vstd[c])
			continue;
		if (sz[c] > tot / 2)
			return dfsfind(c, u);
	}
	return u;
}

void dfsps(int u, int p) {
	ps[u][dep] = ps[p][dep] + a[u];
	pss[u][dep] = pss[p][dep] + ps[u][dep];
	len[u][dep] = len[p][dep] + 1;
	for (auto c : adj[u]) {
		if (p == c || vstd[c])
			continue;
		dfsps(c, u);
	}
}

void dfsadd(int u) {
	upd({ps[u][dep], (len[u][dep] + 1) * ps[u][dep] - pss[u][dep]});
	for (auto c : cdec[u]) {
		dfsadd(c);
	}
}

void dfscalc(int u, ll ext) {
	ans = max(ans, pss[u][dep] - len[u][dep] * ext + qry(len[u][dep] - 1));
	for (auto c : cdec[u]) {
		dfscalc(c, ext);
	}
}

void proc(int u) {
	build();
	upd({ps[u][dep], ps[u][dep]});
	for (auto c : cdec[u]) {
		dfscalc(c, a[u]);
		dfsadd(c);
	}
	ans = max(ans, qry(0));
}

void centroid(int u, int p) {
	dfssz(u, 0);
	tot = sz[u];
	int cen = dfsfind(u, 0);
	cdec[p].push_back(cen);
	vstd[cen] = true;

	dfsps(cen, 0);

	for (auto c : adj[cen]) {
		if (vstd[c])
			continue;
		++dep;
		centroid(c, cen);
		--dep;
	}

	proc(cen);
	reverse(cdec[cen].begin(), cdec[cen].end());
	proc(cen);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	centroid(1, 0);
	cout << ans << '\n';
}