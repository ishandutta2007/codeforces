#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
const int MX = 2e5 + 1;

int n, b[MX], p[MX];
oset ft[MX];

void upd(int a, int val, bool t) {
	for ( ; a <= n; a += a & -a) {
		if (t) {
			ft[a].insert(val);
		} else {
			ft[a].erase(val);
		}
	}
}

int qry(int a, int b) {
	int res = 0;
	for ( ; a; a -= a & -a) {
		res += ft[a].order_of_key(b);
	}
	return res;
}

int qry(int a, int b, int c, int d) {
	return qry(d, b + 1) - qry(c - 1, b + 1) - qry(d, a) + qry(c - 1, a);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		p[a] = i;
	}
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		b[i] = p[a];
		upd(i, b[i], true);
	}

	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			cout << qry(a, b, c, d) << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			upd(x, b[x], false);
			upd(y, b[x], true);
			upd(y, b[y], false);
			upd(x, b[y], true);
			swap(b[x], b[y]);
		}
	}
}