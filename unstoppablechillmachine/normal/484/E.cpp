#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 1e5 + 10;

struct Node {
	int len, mx_sum, pref, suf;
	Node() {};
	Node(int l) : len(l), mx_sum(0), pref(0), suf(0) {};
	Node(int l, int m, int p, int s) : len(l), mx_sum(m), pref(p), suf(s) {};
	bool operator==(Node n) {
		return len == n.len && mx_sum == n.mx_sum && pref == n.pref && suf == n.suf;
	} 
};

Node merge(Node a, Node b) {
	if (a == Node(0, 0, 0, 0)) {
		return b;
	}
	if (b == Node(0, 0, 0, 0)) {
		return a;
	}
	return Node(a.len + b.len, max(a.mx_sum, max(b.mx_sum, a.suf + b.pref)), a.pref + b.pref * (a.pref == a.len), b.suf + a.suf * (b.len == b.suf));
}

Node t[4 * N];

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = Node(1, 0, 0, 0);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int need) {
	if (l == r) {
		t[v] = Node(1, 1, 1, 1);
		return;
	}
	int mid = (l + r) / 2;
	if (need <= mid) {
		update(2 * v, l, mid, need);
	}
	else {
		update(2 * v + 1, mid + 1, r, need);
	}
	t[v] = merge(t[2 * v], t[2 * v + 1]);
}

Node get(int v, int l, int r, int a, int b) {
	if (l > b || r < a) {
		return Node(0, 0, 0, 0);
	}
	if (l >= a && r <= b) {
		return t[v];
	}
	int mid = (l + r) / 2;
	return merge(get(2 * v, l, mid, a, b), get(2 * v + 1, mid + 1, r, a, b));
}

struct T {
	int l, r, w, id;
	T() {};
	T(int _l, int _r, int _w, int _id) : l(_l), r(_r), w(_w), id(_id) {}; 
};

signed main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> srt;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		srt.pb(a[i]);
	}	
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	unordered_map<int, int> to;
	for (int i = 0; i < SZ(srt); i++) {
		to[srt[i]] = i + 1;
	}
	vector<vector<int>> have(SZ(srt) + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = to[a[i]];
		have[a[i]].pb(i);
	}
	int m;
	cin >> m;
	vector<int> l(m), r(m), w(m);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> w[i];
	}
	vector<int> L(m, 1), R(m, SZ(srt) + 1);
	for (int iter = 0; iter < 20; iter++) {
		build(1, 1, n);
		vector<bool> ok(m);
		vector<vector<T>> query(SZ(srt) + 1);
		for (int i = 0; i < m; i++) {
			int mid = (L[i] + R[i]) / 2;
			query[mid].pb(T(l[i], r[i], w[i], i));
		}
		for (int i = SZ(srt); i >= 1; i--) {
			for (auto it : have[i]) {
				update(1, 1, n, it);
			}
			for (auto it : query[i]) {
				if (get(1, 1, n, it.l, it.r).mx_sum >= it.w) {
					ok[it.id] = true;
				}
				else {
					ok[it.id] = false;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (ok[i]) {
				L[i] = (L[i] + R[i]) / 2;
			}
			else {
				R[i] = (L[i] + R[i]) / 2;
			}
		}
	} 
	for (int i = 0; i < m; i++) {
		cout << srt[L[i] - 1] << '\n';
	}
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}