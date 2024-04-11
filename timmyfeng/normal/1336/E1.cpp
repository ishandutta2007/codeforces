#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int LOG = 36;
const int MAG = 20;
const int M = (119 << 23) + 1;

int sz, dp[LOG][LOG][1 << (LOG - MAG)], inc[LOG], ans[LOG], m;
ll basis[LOG];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

void upd(ll ma) {
	for (int i = 0; i < m; ++i) {
		if (ma & (1LL << i)) {
			if (!basis[i]) {
				basis[i] = ma;
				++sz;
				return;
			}
			ma ^= basis[i];
		}
	}
}

void solve1() {
	for (int i = 0, j = 0; i < m; ++i) {
		if (basis[i]) {
			swap(basis[i], basis[j++]);
		}
	}

	for (int ma = 0; ma < (1 << sz); ++ma) {
		ll cur = 0;
		for (int i = 0; i < sz; ++i) {
			if (ma & (1 << i)) {
				cur ^= basis[i];
			}
		}
		++ans[__builtin_popcountll(cur)];
	}
}

void solve2() {
	for (int i = 0; i < m; ++i) {
		if (basis[i]) {
			for (int j = 0; j < i; ++j) {
				if (basis[j] & (1LL << i)) {
					basis[j] ^= basis[i];
				}
			}
		}
	}

	for (int i = 0, j = 0; i < m; ++i) {
		if (basis[i]) {
			for (int k = 0, h = 0; k < m; ++k) {
				if (!basis[k]) {
					if (basis[i] & (1LL << k)) {
						inc[j] |= 1 << h;
					}
					++h;
				}
			}
			++j;
		}
	}

	int cmp = m - sz;
	dp[0][0][0] = 1;
	for (int i = 1; i <= sz; ++i) {
		for (int j = 0; j <= sz; ++j) {
			for (int ma = 0; ma < (1 << cmp); ++ma) {
				dp[i][j][ma] = dp[i - 1][j][ma];
				if (j) {
					dp[i][j][ma] = add(dp[i][j][ma], dp[i - 1][j - 1][ma ^ inc[i - 1]]);
				}
			}
		}
	}

	for (int i = 0; i <= sz; ++i) {
		for (int ma = 0; ma < (1 << cmp); ++ma) {
			ans[__builtin_popcount(ma) + i] += dp[sz][i][ma];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		upd(a);
	}

	if (sz > MAG) {
		solve2();
	} else {
		solve1();
	}

	int ext = 1;
	for (int i = 0; i < n - sz; ++i) {
		ext = add(ext, ext);
	}
	for (int i = 0; i <= m; ++i) {
		ans[i] = mul(ans[i], ext);
		cout << ans[i] << ' ';
	}
	cout << '\n';
}