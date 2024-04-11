#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e6 + 1;

int m;

struct fen_tree {
	ll ft[MX];

	void upd(int a, int val) {
		for (++a; a <= m; a += a & -a) {
			ft[a] += val;
		}
	}

	ll qry(int a) {
		ll res = 0;
		for (++a; a; a -= a & -a) {
			res += ft[a];
		}
		return res;
	}
} fen_tree_cnt, fen_tree_sum;

vector<int> z_func(const string& s) {
	int n = s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		z[i] = i >= r ? 0 : min(z[i - l], r - i);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}

string rev(string a) {
	reverse(a.begin(), a.end());
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string a, b, s;
	cin >> n >> m >> a >> b >> s;

	vector<int> pre = z_func(s.substr(0, m - 1) + '#' + a);
	vector<int> suf = z_func(rev(s.substr(1, m - 1)) + '#' + rev(b));
	pre.erase(pre.begin(), pre.begin() + m);
	suf.erase(suf.begin(), suf.begin() + m);
	reverse(suf.begin(), suf.end());

	ll ans = 0;
	for (int i = 2 - m; i < n; ++i) {
		if (i + m - 2 < n) {
			int val = m - 1 - suf[i + m - 2];
			fen_tree_cnt.upd(val, 1);
			fen_tree_sum.upd(val, val);
		}
		if (i >= 0) {
			ans += pre[i] * fen_tree_cnt.qry(pre[i]) - fen_tree_sum.qry(pre[i]);

			int val = m - 1 - suf[i];
			fen_tree_cnt.upd(val, -1);
			fen_tree_sum.upd(val, -val);
		}
	}
	cout << ans << '\n';
}