#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;
const int MXW = 30;

int basis[MXW], par[MX], sz[MX], val[MX], q;
vector<array<int, 3>> qry_tree[MX * 4];
vector<array<int, 2>> stk;
array<int, 2> req[MX];

void upd_basis(int a) {
	for (int i = MXW - 1; i >= 0; --i) {
		if (a & (1 << i)) {
			if (basis[i]) {
				a ^= basis[i];
			} else {
				basis[i] = a;
				return;
			}
		}
	}
}

int find(int a) {
	return par[a] == a ? a : find(par[a]);
}

int qry_path(int a) {
	return val[a] ^ (par[a] == a ? 0 : qry_path(par[a]));
}

bool unite(int a, int b, int w) {
	w ^= qry_path(a) ^ qry_path(b);
	a = find(a);
	b = find(b);
	if (a == b)
		return false;

	if (sz[a] > sz[b]) {
		swap(a, b);
	}
	sz[b] += sz[a];
	par[a] = b;
	val[a] = w;

	stk.push_back({a, b});
	return true;
}

void roll_back() {
	array<int, 2> op = stk.back();
	stk.pop_back();

	val[op[0]] = 0;
	par[op[0]] = op[0];
	sz[op[1]] -= sz[op[0]];
}

void dfs(int v, int l, int r) {
	int roll = 0;
	vector<int> pre_basis(basis, basis + MXW);
	for (auto e : qry_tree[v]) {
		if (unite(e[0], e[1], e[2])) {
			++roll;
		} else {
			upd_basis(qry_path(e[0]) ^ qry_path(e[1]) ^ e[2]);
		}
	}

	if (l == r) {
		if (req[l][0]) {
			int res = qry_path(req[l][0]) ^ qry_path(req[l][1]);
			for (int i = MXW - 1; i >= 0; --i) {
				if (res & (1 << i)) {
					res ^= basis[i];
				}
			}
			cout << res << '\n';
		}
	} else {
		int m = (l + r) / 2;
		dfs(v * 2, l, m);
		dfs(v * 2 + 1, m + 1, r);
	}

	while (roll--) {
		roll_back();
	}
	copy(pre_basis.begin(), pre_basis.end(), basis);
}

void upd_qry(array<int, 3> e, int a, int b, int v = 1, int l = 0, int r = q - 1) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		qry_tree[v].push_back(e);
	} else {
		int m = (l + r) / 2;
		upd_qry(e, a, b, v * 2, l, m);
		upd_qry(e, a, b, v * 2 + 1, m + 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	map<array<int, 2>, array<int, 2>> mp;
	while (m--) {
		int w;
		array<int, 2> e;
		cin >> e[0] >> e[1] >> w;
		mp[e] = {0, w};
	}

	cin >> q;
	for (int i = 0; i < q; ++i) {
		int type;
		array<int, 2> e;
		cin >> type >> e[0] >> e[1];
		if (type == 1) {
			int w;
			cin >> w;
			mp[e] = {i, w};
		} else if (type == 2) {
			upd_qry({e[0], e[1], mp[e][1]}, mp[e][0], i);
			mp.erase(e);
		} else {
			req[i] = e;
		}
	}

	for (auto e : mp) {
		upd_qry({e.first[0], e.first[1], e.second[1]}, e.second[0], q - 1);
	}

	iota(par, par + n + 1, 0);
	fill(sz, sz + n + 1, 1);

	dfs(1, 0, q - 1);
}