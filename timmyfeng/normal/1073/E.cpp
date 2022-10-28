#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int LOGN = 19;
const int M = (119 << 23) + 1;

int pows10[LOGN], dpSum[LOGN][1 << 10][2], dp[LOGN][1 << 10][2], k;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

void init() {
	pows10[0] = 1;
	for (int i = 1; i < LOGN; ++i) {
		pows10[i] = mul(pows10[i - 1], 10);
	}
}

int calc(string s) {
	int n = s.size();
	memset(dpSum, 0, sizeof dpSum);
	memset(dp, 0, sizeof dp);
	dp[0][0][1] = 1;
	for (int i = 0; i < n; ++i) {
		for (int ma = 0; ma < (1 << 10); ++ma) {
			int d = s[i] - '0';
			for (int j = !i; j < 10; ++j) {
				int nMa = ma | (1 << j);
				dp[i + 1][nMa][0] = add(dp[i + 1][nMa][0], dp[i][ma][0]);
				dpSum[i + 1][nMa][0] = add(dpSum[i + 1][nMa][0], 
						add(dpSum[i][ma][0], mul(dp[i][ma][0], mul(pows10[n - i - 1], j))));
				if (j <= d) {
					dp[i + 1][nMa][j == d] = add(dp[i + 1][nMa][j == d], dp[i][ma][1]);
					dpSum[i + 1][nMa][j == d] = add(dpSum[i + 1][nMa][j == d],
							add(dpSum[i][ma][1], mul(dp[i][ma][1], mul(pows10[n - i - 1], j))));
				}
			}
		}
	}

	int res = 0;
	for (int ma = 0; ma < (1 << 10); ++ma) {
		if (__builtin_popcount(ma) <= k) {
			res = add(res, add(dpSum[n][ma][0], dpSum[n][ma][1]));
		}
	}
	return res;
}

int solve(ll n) {
	string s = to_string(n);
	int res = 0;
	for (int i = 1; i < (int)s.size(); ++i) {
		res = add(res, calc(string(i, '9')));
	}
	res = add(res, calc(s));
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	ll l, r;
	cin >> l >> r >> k;

	cout << sub(solve(r), solve(l - 1)) << '\n';
}