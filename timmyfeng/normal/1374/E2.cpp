#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 1;
const int LOG_N = 20;

int perm[MX];
int val[MX];
int ndx[MX];
int t[MX];

struct fen_tree {
	int ft[MX];

	int qry(int a) {
		int res = 0;
		for (++a; a; a -= a & -a) {
			res += ft[a];
		}
		return res;
	}

	void upd(int a, int val) {
		for (++a; a < MX; a += a & -a) {
			ft[a] += val;
		}
	}

	int kth(int k) {
		if (!k) {
			return -1;
		}
		int res = 0;
		int cur = 0;
		for (int i = LOG_N - 1; i >= 0; --i) {
			if (res + (1 << i) < MX && cur + ft[res + (1 << i)] < k) {
				res += 1 << i;
				cur += ft[res];
			}
		}
		return res;
	}
} ft_cnt, ft_sum;

void upd(int i, int a) {
	ft_cnt.upd(i, a * 1);
	ft_sum.upd(i, a * t[perm[i]]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> books(4, vector<pair<int, int>>(1, make_pair(0, 0)));
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> t[i] >> a >> b;
		books[a * 2 + b].emplace_back(t[i], i);
	}

	iota(perm, perm + n, 0);
	sort(perm, perm + n, [&](int a, int b) {
		return t[a] < t[b];
	});

	for (int i = 0; i < n; ++i) {
		ndx[perm[i]] = i;
		upd(i, 1);
	}

	for (int i = 0; i < 4; ++i) {
		sort(books[i].begin(), books[i].end());
		for (int j = 1; j < int(books[i].size()); ++j) {
			books[i][j].first += books[i][j - 1].first;
		}
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= 2; ++j) {
			if (i < int(books[j].size())) {
				upd(ndx[books[j][i].second], -1);
			}
		}
	}

	int best = -1;
	int ans = 2e9 + 1;
	for (int i = 0; i < int(books[3].size()); ++i) {
		if (i) {
			upd(ndx[books[3][i].second], -1);
		}

		int rem = m - i - 2 * (k - i);
		if (rem >= 0 &&
				k - i >= 0 &&
				k - i < int(min(books[1].size(), books[2].size()))) {
			int ndx = ft_cnt.kth(rem);
			int res = ft_sum.qry(ndx) + books[1][k - i].first + books[2][k - i].first + books[3][i].first;
			if (res < ans) {
				ans = res;
				best = i;
			}
		}

		if (k - i > 0) {
			for (int j = 1; j <= 2; ++j) {
				if (k - i < int(books[j].size())) {
					upd(ndx[books[j][k - i].second], 1);
				}
			}
		}
	}

	if (best == -1) {
		cout << -1 << "\n";
	} else {
		cout << ans << "\n";
		vector<bool> used(n);
		for (int i = 1; i <= best; ++i) {
			used[books[3][i].second] = true;
		}
		for (int i = 1; i <= k - best; ++i) {
			for (int j = 1; j <= 2; ++j) {
				used[books[j][i].second] = true;
			}
		}
		vector<pair<int, int>> oth;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				oth.emplace_back(t[i], i);
			}
		}
		sort(oth.begin(), oth.end());
		int rem = m - best - 2 * (k - best);
		for (int i = 0; i < rem; ++i) {
			used[oth[i].second] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				cout << i + 1 << " ";
			}
		}
		cout << "\n";
	}
}