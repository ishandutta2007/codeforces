#include <bits/stdc++.h>
using namespace std;

const int MOD = (119 << 23) + 1;
const int N = 2001;

int dp[N][N];
int a[N][N];
int fact[N];

template <class T>
struct fenwick_tree {

	vector<T> tree;
	int n;

	fenwick_tree(int _n) : tree(_n + 1), n(_n) {}

	void update(int a, T val) {
		for ( ; a <= n; a += a & -a) {
			tree[a] += val;
		}
	}

	T query(int a) {
		int res = 0;
		for ( ; a; a -= a & -a) {
			res += tree[a];
		}
		return res;
	}

	T query(int a, int b) {
		return query(b) - query(a - 1);
	}

};

int add(int a, int b) {
	return (a += b) < MOD ? a : a - MOD;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + MOD : a;
}

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = mul(dp[i - 1][0], i);
		for (int j = 1; j <= i; ++j) {
			dp[i][j] = sub(dp[i][j - 1], dp[i - 1][j - 1]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int res = 0;
		int k = 0;

		fenwick_tree<int> no_demand(n);
		fenwick_tree<int> demand(n);
		for (int j = 1; j <= n; ++j) {
			if (i > 0) {
				demand.update(j, 1);
				++k;
			} else {
				no_demand.update(j, 1);
			}
		}

		for (int j = 0; j < n - 1; ++j) {
			int cnt_a = no_demand.query(a[i][j] - 1);
			int cnt_b = demand.query(a[i][j] - 1);

			if (i > 0) {
				if (demand.query(a[i - 1][j], a[i - 1][j]) > 0) {
					cnt_b -= (a[i - 1][j] < a[i][j]);
					no_demand.update(a[i - 1][j], 1);
					demand.update(a[i - 1][j], -1);
					--k;
				}
			}

			res = add(res, mul(cnt_a, dp[n - 1 - j][k]));
			if (k > 0) {
				res = add(res, mul(cnt_b, dp[n - 1 - j][k - 1]));
			}

			if (demand.query(a[i][j], a[i][j]) > 0) {
				demand.update(a[i][j], -1);
				--k;
			} else {
				no_demand.update(a[i][j], -1);
			}
		}

		ans = add(ans, mul(res, mod_pow(dp[n][n], n - 1 - i)));
	}
	cout << ans << "\n";
}