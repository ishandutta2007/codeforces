#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

int pos[MX], n, log_n;

struct fen_tree {
	ll ft[MX];

	void upd(int a, ll val) {
		for ( ; a <= n; a += a & -a) {
			ft[a] += val;
		}
	}

	ll qry(int a) {
		ll res = 0;
		for ( ; a; a -= a & -a) {
			res += ft[a];
		}
		return res;
	}

	int kth(ll a) {
		ll sum = 0;
		int res = 0;
		for (int i = log_n - 1; i >= 0; --i) {
			int len = 1 << i;
			if (res + len <= n && sum + ft[res + len] < a) {
				res += len;
				sum += ft[res];
			}
		}
		return res + 1;
	}
} ft_cnt, ft_pos;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	log_n = 32 - __builtin_clz(n);

	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		pos[a] = i;
	}

	ll inv = 0;
	ll offset = 0;
	for (int i = 1; i <= n; ++i) {
		ft_cnt.upd(pos[i], 1);
		ft_pos.upd(pos[i], pos[i]);

		inv += i - ft_cnt.qry(pos[i]);
		
		int m = (i + 1) / 2;
		int ndx = ft_cnt.kth(m);
		ll move_cnt = ll(2 * m - i) * ndx + ft_pos.qry(n) - 2 * ft_pos.qry(ndx);

		cout << inv + move_cnt - offset << ' ';
		offset += (i + 1) / 2;
	}
	cout << '\n';
}