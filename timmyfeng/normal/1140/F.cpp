#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;

int par[MX * 2], szx[MX * 2], szy[MX * 2], n;
vector<pair<int, int>> stk, st[MX * 4];
ll res, ans[MX];

int find(int a) {
	if (a == par[a])
		return a;
	return find(par[a]);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (szx[a] + szy[a] > szx[b] + szy[b]) {
		swap(a, b);
	}
	par[a] = b;
	res -= (ll)szx[a] * szy[a] + (ll)szx[b] * szy[b];
	szx[b] += szx[a];
	szy[b] += szy[a];
	res += (ll)szx[b] * szy[b];
	stk.emplace_back(a, b);
	return true;
}

void rollback() {
	auto [a, b] = stk.back();
	stk.pop_back();
	res -= (ll)szx[b] * szy[b];
	szx[b] -= szx[a];
	szy[b] -= szy[a];
	res += (ll)szx[b] * szy[b] + (ll)szx[a] * szy[a];
	par[a] = a;
}

void upd(int a, int b, pair<int, int> val, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		st[v].push_back(val);
	} else {
		int m = (l + r) / 2;
		upd(a, b, val, v * 2, l, m);
		upd(a, b, val, v * 2 + 1, m + 1, r);
	}
}

void dfs(int v = 1, int l = 0, int r = n - 1) {
	int cnt = 0;
	for (auto [x, y] : st[v]) {
		cnt += unite(x, MX + y);
	}

	if (l == r) {
		ans[l] = res;
	} else {
		int m = (l + r) / 2;
		dfs(v * 2, l, m);
		dfs(v * 2 + 1, m + 1, r);
	}

	while (cnt--) {
		rollback();
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	map<pair<int, int>, int> mp;
	for (int i = 0; i < n; ++i) {
		pair<int, int> q;
		cin >> q.first >> q.second;
		if (mp.count(q)) {
			upd(mp[q], i - 1, q);
			mp.erase(q);
		} else {
			mp[q] = i;
		}
	}
	for (auto [q, t] : mp) {
		upd(t, n - 1, q);
	}

	iota(par, par + 2 * MX, 0);
	fill(szx + 1, szx + MX, 1);
	fill(szy + 1 + MX, szy + 2 * MX, 1);

	dfs();
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}