#include <bits/stdc++.h> 
using namespace std;

const int MX = 5e5 + 1;

tuple<int, int, int> req[MX];
pair<int, int> st[MX * 2];
int a[MX], ans[MX], n;
vector<int> pos[MX];

void upd(int a, int val) {
	a += n;
	st[a] = {val, a - n};
	for (a /= 2; a; a /= 2) {
		st[a] = min(st[a * 2], st[a * 2 + 1]);
	}
}

pair<int, int> qry(int a, int b) {
	pair<int, int> res = {n, 0};
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			res = min(res, st[a++]);
		}
		if (b % 2 == 0) {
			res = min(res, st[b--]);
		}
	}
	return res;
}

void add(int a) {
	int cnt = pos[a].size();
	if (cnt) {
		upd(pos[a][cnt - 1], cnt > 1 ? pos[a][cnt - 2] : -1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		req[i] = make_tuple(r - 1, l - 1, i);
	}
	sort(req, req + q, greater<tuple<int, int, int>>());


	fill(st, st + 2 * n, make_pair(n, 0));
	for (int i = 1; i < MX; ++i) {
		add(i);
	}

	int cur_r = n - 1;
	for (int i = 0; i < q; ++i) {
		auto [r, l, j] = req[i];
		while (cur_r > r) {
			pos[a[cur_r]].pop_back();
			add(a[cur_r]);
			--cur_r;
		}
		auto res = qry(l, r);
		ans[j] = res.first < l ? a[res.second] : 0;
	}

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}