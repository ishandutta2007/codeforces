#include <bits/stdc++.h>
using namespace std;

const int maxn = 300005;

struct Node {
	int s;
	int tag;
} st[4 * maxn];

void upd(int node, int v) {
	if (!v) return;
	if (!st[node].tag) { st[node].tag = v; return; }
	if (st[node].tag == 1 && v == 1) st[node].tag = 1;
	else if (st[node].tag == 1 && v == 2) st[node].tag = 2;
	else if (st[node].tag == 1 && v == 3) st[node].tag = 2;
	else if (st[node].tag == 2 && v == 1) st[node].tag = 1;
	else if (st[node].tag == 2 && v == 2) st[node].tag = 2;
	else if (st[node].tag == 2 && v == 3) st[node].tag = 1;
	else if (st[node].tag == 3 && v == 1) st[node].tag = 1;
	else if (st[node].tag == 3 && v == 2) st[node].tag = 2;
	else if (st[node].tag == 3 && v == 3) st[node].tag = 0;
}

void push(int node, int l, int r) {
	if (!st[node].tag) return;
	if (st[node].tag == 1) {
		st[node].s = r - l + 1;
	}
	if (st[node].tag == 2) {
		st[node].s = 0;
	}
	if (st[node].tag == 3) {
		st[node].s = r - l + 1 - st[node].s;
	}
	if (l != r) {
		upd(node << 1, st[node].tag);
		upd(node << 1 | 1, st[node].tag);
	}
	st[node].tag = 0;
}

void Build(int node, int l, int r) {
	st[node].s = 0;
	st[node].tag = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	Build(node << 1, l, mid);
	Build(node << 1 | 1, mid + 1, r);
}

void Update(int node, int l, int r, int tl, int tr, int x) {
	push(node, l, r);
	if (l > r || l > tr || r < tl) return;
	if (tl <= l && r <= tr) {
		st[node].tag = x;
		push(node, l, r);
		return;
	}
	int mid = l + r >> 1;
	Update(node << 1, l, mid, tl, tr, x);
	Update(node << 1 | 1, mid + 1, r, tl, tr, x);
	st[node].s = st[node << 1].s + st[node << 1 | 1].s;
}

int find_first(int node, int l, int r) {
	push(node, l, r);
	if (l == r) return l;
	int mid = l + r >> 1;
	push(node << 1, l, mid);
	push(node << 1 | 1, mid + 1, r);
	if (st[node << 1].s == mid - l + 1) return find_first(node << 1 | 1, mid + 1, r);
	else return find_first(node << 1, l, mid);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cout << fixed << setprecision(6);

	int n;
	cin >> n;

	vector<long long> l(n), r(n), t(n);
	vector<long long> compress(1, 1);
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> l[i] >> r[i];
		compress.push_back(l[i]);
		compress.push_back(r[i]);
		compress.push_back(r[i] + 1);
	}

	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());

	auto get_val = [&](long long x) {
		return lower_bound(compress.begin(), compress.end(), x) - compress.begin();
	};

	int m = compress.size();

	Build(1, 0, m - 1);

	for (int i = 0; i < n; ++i) {
		Update(1, 0, m - 1, get_val(l[i]), get_val(r[i]), t[i]);
		cout << compress[find_first(1, 0, m - 1)] << "\n";
	}

	return 0;
}