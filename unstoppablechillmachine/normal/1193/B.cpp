#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define int ll

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> g[N];
pair<int, int> vl[N];
set<int> have[N];
int k, ind[N];

mt19937 rnd(228);

struct Treap {
	struct Node {
		int x, y, L, R;
		ll val, mx, push_mx, push_add;
		Node() : x(0), y(rnd()), L(0), R(0), val(0), mx(0), push_mx(0), push_add(0) {};
		Node(int x, int y, int L, int R, ll val, ll mx, ll push_mx, ll push_add) : x(x), y(y), L(L), R(R), val(val), mx(mx), push_mx(push_mx), push_add(push_add) {};
	};
	vector<Node> t;
	int root, cnt;
	Treap() {
		t.pb(Node());
		cnt = 0;
		root = 0;
	}
	void upd(int v) {
		if (!v) {
			return;
		}
		if (t[v].L) {
			if (t[v].push_add) {
				t[t[v].L].push_add += t[v].push_add;
				t[t[v].L].val += t[v].push_add;
				t[t[v].L].mx += t[v].push_add;
			}
			if (t[v].push_mx) {
				t[t[v].L].push_mx = max(t[t[v].L].push_mx, t[v].push_mx);
				t[t[v].L].val = max(t[t[v].L].val, t[v].push_mx);
				t[t[v].L].mx = max(t[t[v].L].mx, t[v].push_mx);
			}
		}
		if (t[v].R) {
			if (t[v].push_add) {
				t[t[v].R].push_add += t[v].push_add;
				t[t[v].R].val += t[v].push_add;
				t[t[v].R].mx += t[v].push_add;
			}
			if (t[v].push_mx) {
				t[t[v].R].push_mx = max(t[t[v].R].push_mx, t[v].push_mx);
				t[t[v].R].val = max(t[t[v].R].val, t[v].push_mx);
				t[t[v].R].mx = max(t[t[v].R].mx, t[v].push_mx);
			}
		}
		t[v].push_mx = 0;
		t[v].push_add = 0;
		t[v].mx = max(t[v].val, max(t[t[v].L].mx, t[t[v].R].mx));
	}
	pair<int, int> split(int v, int x) {
		if (!v) {
			return {0, 0};
		}
		upd(v);
		if (t[v].x <= x) {
			pair<int, int> sp = split(t[v].R, x);
			t[v].R = sp.F;
			upd(v);
			upd(sp.S);
			return {v, sp.S};
		}
		else {
			pair<int, int> sp = split(t[v].L, x);
			t[v].L = sp.S;
			upd(v);
			upd(sp.F);
			return {sp.F, v};
		}
	}
	int merge(int v1, int v2) {
		if (!v1) {
			return v2;
		}
		if (!v2) {
			return v1;
		}
		upd(v1);
		upd(v2);
		if (t[v1].y > t[v2].y) {
			t[v1].R = merge(t[v1].R, v2);
			upd(v1);
			return v1;
		}
		else {
			t[v2].L = merge(v1, t[v2].L);
			upd(v2);
			return v2;
		}
	}
	void out(int v) {
		if (!v) {
			return;
		}
		//upd(v);
		out(t[v].L);
		cout << t[v].x << ' ' << t[v].val << ' ' << t[v].mx << ' ' << t[v].push_mx << ' ' << t[v].push_add << endl;
		out(t[v].R);
	}
	int get_max(int r) {
		pair<int, int> sp = split(root, r);
		int res = (sp.F ? t[sp.F].mx : 0);
		root = merge(sp.F, sp.S);
		return res;
	}
	void add(int l, int r, ll delta) {
		pair<int, int> sp = split(root, r);
		pair<int, int> sp2 = split(sp.F, l - 1);
		if (sp2.S) {
			t[sp2.S].push_add += delta;
			t[sp2.S].val += delta;
			t[sp2.S].mx += delta;
		}
		root = merge(sp2.F, sp2.S);
		root = merge(root, sp.S);
	}
	void upd_val(int l, int r, ll vl) {
		pair<int, int> sp = split(root, r);
		pair<int, int> sp2 = split(sp.F, l - 1);
		if (sp2.S) {
			t[sp2.S].val = max(t[sp2.S].val, vl);
			t[sp2.S].push_mx = max(t[sp2.S].push_mx, vl);
			t[sp2.S].mx = max(t[sp2.S].mx, vl);
		}
		root = merge(sp2.F, sp2.S);
		root = merge(root, sp.S);	
	}
	void insert(int v, ll val) {
		cnt++;
		t.pb(Node(v, rnd(), 0, 0, val, val, 0, 0));
		pair<int, int> sp = split(root, v);
		root = merge(sp.F, cnt);
		root = merge(root, sp.S);
	}
};

Treap tree[N];

void dfs(int v) {
	tree[v] = Treap();
	ind[v] = v;
	for (auto u : g[v]) {
		dfs(u);
		if (SZ(have[ind[u]]) > SZ(have[ind[v]])) {
			swap(ind[v], ind[u]);
		}
		vector<pair<int, int>> to_insert;
		for (auto it : have[ind[u]]) {
			if (have[ind[v]].find(it) == have[ind[v]].end()) {
				to_insert.pb({it, tree[ind[v]].get_max(it) + tree[ind[u]].get_max(it)});
			}			
		}
		auto IT = have[ind[u]].begin();
		while (IT != have[ind[u]].end()) {
			auto IT2 = IT;
			IT2++;
			if (IT2 != have[ind[u]].end()) {
				tree[ind[v]].add(*IT, *IT2 - 1, tree[ind[u]].get_max(*IT));
			}
			else {
				tree[ind[v]].add(*IT, k, tree[ind[u]].get_max(*IT));
			}
			IT++;
		}
		for (auto it : to_insert) {
			tree[ind[v]].insert(it.F, it.S);
		}
		for (auto it : have[ind[u]]) {
			have[ind[v]].insert(it);
		}
	}
	if (vl[v].F) {
		ll mx = tree[ind[v]].get_max(vl[v].F);
		if (have[v].find(vl[v].F) != have[v].end()) {
			tree[ind[v]].upd_val(vl[v].F, vl[v].F, mx + vl[v].S);
		}
		else {
			tree[ind[v]].insert(vl[v].F, mx + vl[v].S);
			tree[ind[v]].upd_val(vl[v].F + 1, k, mx + vl[v].S);
		}
		have[ind[v]].insert(vl[v].F);
	}
}

vector<pair<int, int>> has[N];

bool check(vector<pair<int, int>> &a, int x) {
	for (auto it : a) {
		if (it.F == x) {
			return true;
		}
	}
	return false;
}

void ins(vector<pair<int, int>> &a, int x, int y) {
	int pos = 0;
	while (pos < SZ(a) && a[pos].F < x) {
		pos++;
	}
	a.insert(a.begin() + pos, make_pair(x, y));
}
 
void add(vector<pair<int, int>> &a, int x, int y) {
	for (auto &it : a) {
		if (it.F >= x) {
			it.S += y;
		}
	}
}
 
void upd_val(vector<pair<int, int>> &a, int x, int y) {
	for (auto &it : a) {
		if (it.F == x) {
			it.S = max(it.S, y);
		}
	}
}
 
int get_max(vector<pair<int, int>> &a, int x) {
	int res = 0;
	for (auto it : a) {
		if (it.F <= x) {
			res = max(res, it.S);
		}
	}
	return res;
}

void dfs2(int v) {
	set<int> vals;
	for (auto u : g[v]) {
		dfs2(u);
		for (auto it : has[u]) {
			vals.insert(it.F);
		}
	}
	for (auto it : vals) {
		has[v].pb({it, 0});
		for (auto u : g[v]) {
			int mx = 0;
			for (auto kek : has[u]) {
				if (kek.F <= it) {
					mx = max(mx, kek.S);
				}
			}
			has[v].back().S += mx;
		}
	}
	if (vl[v].F) {
		int mx = get_max(has[v], vl[v].F);
		if (check(has[v], vl[v].F)) {
			upd_val(has[v], vl[v].F, mx + vl[v].S);
		}
		else {
			ins(has[v], vl[v].F, mx + vl[v].S);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		g[p].pb(i);
	}	
	for (int i = 1; i <= m; i++) {
		int v, day, cost;
		cin >> v >> day >> cost;
		vl[v] = {day, cost};
	}
	if (k <= 20) {
		dfs2(1);
		int ans = 0;
			for (auto it : has[1]) {
				ans = max(ans, it.S);
			}
			cout << ans << '\n';
			exit(0);
	}
	dfs(1);
	cout << tree[ind[1]].get_max(k) << '\n';
}