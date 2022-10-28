#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5;
const int INF = 1e9;

int n, k;

struct Node {
	vector<int> mx, mn;
	
	Node(vector<int>& a) : mx(1 << k), mn(1 << k) {
		for (int ma = 0; ma < (1 << k); ++ma) {
			int res = 0;
			for (int i = 0; i < k; ++i) {
				if (ma & (1 << i)) {
					res += a[i];
				} else {
					res -= a[i];
				}
			}
			mx[ma] = mn[ma] = res;
		}
	}

	Node() : mx(1 << k, -INF), mn(1 << k, INF) { }
} st[MX * 2];

Node combine(Node& a, Node& b) {
	Node res;
	for (int i = 0; i < (1 << k); ++i) {
		res.mn[i] = min(a.mn[i], b.mn[i]);
		res.mx[i] = max(a.mx[i], b.mx[i]);
	}
	return move(res);
}

Node qry(int a, int b) {
	Node res;
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res = combine(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = combine(res, st[b--]);
		}
	}
	return res;
}

void upd(int a, vector<int>& val) {
	a += n;
	st[a] = Node(val);
	for (a /= 2; a; a /= 2) {
		st[a] = combine(st[a * 2], st[a * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		vector<int> a(k);
		for (auto& j : a) {
			cin >> j;
		}
		st[i + n] = Node(a);
	}
	for (int i = n - 1; i; --i) {
		st[i] = combine(st[i * 2], st[i * 2 + 1]);
	}

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			cin >> i;
			vector<int> a(k);
			for (auto& j : a) {
				cin >> j;
			}
			upd(i - 1, a);
		} else {
			int l, r;
			cin >> l >> r;
			Node res = qry(l - 1, r - 1);
			int ans = 0;
			for (int ma = 0; ma < (1 << k); ++ma) {
				ans = max(ans, res.mx[ma] - res.mn[ma]);
			}
			cout << ans << '\n';
		}
	}
}