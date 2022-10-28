#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(ll a, ll b, ll c) {
	return (c - a) * (c - a) + (b - a) * (b - a) + (c - b) * (c - b);
}

ll proc(int a, vector<int>& b, int c) {
	ll res = 8e18;
	int u = lower_bound(b.begin(), b.end(), (a + c) / 2) - b.begin();
	if (u < b.size() && b[u] <= c) {
		res = min(res, calc(a, b[u], c)); 
	}
	if (u && b[u - 1] >= a) {
		res = min(res, calc(a, b[u - 1], c));
	}
	return res;
}

ll solve(vector<int>& a, vector<int>& b, vector<int>& c) {
	ll res = 8e18;
	for (int w = 0; w < a.size(); ++w) {
		int u = lower_bound(b.begin(), b.end(), a[w]) - b.begin();
		int v = lower_bound(c.begin(), c.end(), a[w]) - c.begin();
		if (u == b.size() || v == c.size()) break;
		if (b[u] >= c[v]) {
			res = min(res, proc(a[w], c, b[u]));
		}
		if (c[v] >= b[u]) {
			res = min(res, proc(a[w], b, c[v]));
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x, y, z;
		cin >> x >> y >> z;
		vector<int> r(x), g(y), b(z);
		for (auto& i : r) {
			cin >> i;
		}
		for (auto& i : g) {
			cin >> i;
		}
		for (auto& i : b) {
			cin >> i;
		}
		sort(r.begin(), r.end());
		sort(g.begin(), g.end());
		sort(b.begin(), b.end());
		cout << min({
				solve(r, g, b),
				solve(g, b, r),
				solve(b, r, g)
		}) << '\n';
	}
}