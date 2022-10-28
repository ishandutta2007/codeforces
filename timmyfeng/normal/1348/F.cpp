#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

vector<tuple<int, int, int>> seg;
int a[MX], b[MX], ans[MX], n;
pair<int, int> st[MX * 2];

void upd(int a, pair<int, int> val) {
	a += n - 1;
	st[a] = val;
	for (a /= 2; a; a /= 2) {
		st[a] = max(st[a * 2], st[a * 2 + 1]);
	}
}

pair<int, int> qry(int a, int b) {
	pair<int, int> res;
	for (a += n - 1, b += n - 1; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res = max(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = max(res, st[b--]);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		seg.emplace_back(a[i], b[i], i);
	}
	sort(seg.begin(), seg.end());

	int ndx = 0;
	pair<int, int> swp;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cur;
	for (int i = 1; i <= n; ++i) {
		while (ndx < n && get<0>(seg[ndx]) <= i) {
			cur.emplace(get<1>(seg[ndx]), get<2>(seg[ndx]));
			++ndx;
		}
		int opt = cur.top().second;
		ans[opt] = i;
		cur.pop();
		auto mat = qry(i, n);
		if (mat.first >= a[opt]) {
			swp = {mat.second, opt};
		}
		upd(b[opt], {i, opt});
	}

	auto out = [&]() {
		for (int i = 0; i < n; ++i) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
	};

	if (swp.first || swp.second) {
		cout << "NO" << '\n';
		out();
		swap(ans[swp.first], ans[swp.second]);
		out();
	} else {
		cout << "YES" << '\n';
		out();
	}
}