#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 100;

int dp[MX + 1][10][1 << 4][2][10][1 << 4][2], n, mxk;
string s;

int add(int a, int b) {
	return a + b >= M ? a + b - M : a + b;
}
 
int mul(int a, int b) {
	return (long long)a * b % M;
}

vector<tuple<int, int, int>> gettrans(int len, int car, int ma, int cmp, int a, int d) {
	int digit = d * a + car;
	car = digit / 10;
	digit %= 10;
	if (digit % a == 0 && digit / a <= mxk && digit >= a) {
		ma |= 1 << (digit / a - 1);
	}

	vector<tuple<int, int, int>> res;
	if (!cmp) {
		res.emplace_back(car, ma, false);
	}
	if ((digit < s[len] && !cmp) || (digit == s[len] && cmp)) {
		res.emplace_back(car, ma, true);
	}
	return res;
}

int solve(int a, int b) {
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[0][0][0][i][0][0][j] = 1;
		}
	}
	mxk = 9 / b;

	for (int len = 0; len < n; ++len) {
		for (int cara = 0; cara < 10; ++cara) {
		for (int maa = 0; maa < (1 << mxk); ++maa) {
		for (int cmpa = 0; cmpa < 2; ++cmpa) {
			for (int carb = 0; carb < 10; ++carb) {
			for (int mab = 0; mab < (1 << mxk); ++mab) {
			for (int cmpb = 0; cmpb < 2; ++cmpb) {
				if (!dp[len][cara][maa][cmpa][carb][mab][cmpb]) continue;
				for (int i = 0; i < 10; ++i) {
					for (auto [t, u, v] : gettrans(len, cara, maa, cmpa, a, i)) {
						for (auto [q, r, s] : gettrans(len, carb, mab, cmpb, b, i)) {
							dp[len + 1][t][u][v][q][r][s] = 
									add(dp[len + 1][t][u][v][q][r][s], dp[len][cara][maa][cmpa][carb][mab][cmpb]);
						}
					}
				}
			}
			}
			}
		}
		}
		}
	}

	int res = 0;
	for (int maa = 0; maa < (1 << mxk); ++maa) {
		for (int mab = 0; mab < (1 << mxk); ++mab) {
			if (maa & mab) {
				res = add(res, dp[n][0][maa][1][0][mab][1]);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	reverse(s.begin(), s.end());
	for (auto& i : s) {
		i -= '0';
	}
	n = s.size();

	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = add(s[i], mul(ans, 10));
	}
	for (int i = 1; i < 10; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if (__gcd(i, j) != 1) continue;
			int res = solve(i, j);
			ans = add(ans, add(res, res));
		}
	}
	cout << ans << '\n';
}