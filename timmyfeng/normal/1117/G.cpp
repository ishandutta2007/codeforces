#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using pt = pair<ll, ll>;
#define x first
#define y second
const int MX = 1e6 + 1;

tuple<int, int, int> req[MX];
int n, m, a[MX];
ll ans[MX];
pt ft[MX];

ll dot(pt a, pt b) {
	return a.x * b.x + a.y * b.y;
}

pt operator+(pt a, pt b) {
	return {a.x + b.x, a.y + b.y};
}

pt operator-(pt a, pt b) {
	return {a.x - b.x, a.y - b.y};
}

void upd(int a, pt val) {
	for ( ; a <= n; a += a & -a) {
		ft[a] = ft[a] + val;
	}
}

pt qry(int a) {
	pt res;
	for ( ; a; a -= a & -a) {
		res = res + ft[a];
	}
	return res;
}

pt qry(int a, int b) {
	return qry(b) - qry(a - 1);
}

void solve() {
	sort(req, req + m, [](tuple<int, int, int> a, tuple<int, int, int> b) {
		return get<1>(a) < get<1>(b);
	});

	int ndx = 0;
	vector<int> stk;
	for (int i = 1; i <= n; ++i) {
		while (!stk.empty() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}

		pt f1 = {-1, i};
		upd(i, f1);
		if (!stk.empty()) {
			pt f2 = {0, i - stk.back() - 1};
			upd(stk.back(), f2 - f1);
		}

		for ( ; ndx < m && get<1>(req[ndx]) == i; ++ndx) {
			auto [a, b, k] = req[ndx];
			ans[k] += dot(qry(a, b), {a, 1});
		}
		stk.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> get<0>(req[i]);
	}
	for (int i = 0; i < m; ++i) {
		auto& [a, b, k] = req[i];
		cin >> b;
		k = i;
		ans[k] += b - a + 1;
	}

	solve();
	reverse(a + 1, a + 1 + n);
	for (int i = 0; i < m; ++i) {
		auto& [a, b, k] = req[i];
		swap(a, b);
		a = n - a + 1;
		b = n - b + 1;
	}
	fill(ft, ft + n + 1, pt{0, 0});
	solve();

	for (int i = 0; i < m; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}