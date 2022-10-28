#include <bits/stdc++.h> 
using namespace std;

const int MX = 51;
const int M = (119 << 23) + 1;

int add(int a, int b) {
	int res = a + b;
	return res < M ? res : res - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int l[MX], r[MX], dp[MX * 2][MX], comb[MX * 2][MX];

int modpow(int a, int b) {
	if (!b)
		return 1;
	if (b % 2)
		return mul(a, modpow(a, b - 1));
	int tmp = modpow(a, b / 2);
	return mul(tmp, tmp);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, tot = 1;
	cin >> n;
	vector<int> pt;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		pt.push_back(l[i]);
		pt.push_back(++r[i]);
		tot = mul(tot, r[i] - l[i]);
	}

	sort(pt.begin(), pt.end());
	pt.resize(unique(pt.begin(), pt.end()) - pt.begin());
	pt.push_back(M - 1);
	int m = pt.size();

	for (int i = 1; i < m; ++i) {
		comb[i][0] = 1;
		int base = pt[i] - pt[i - 1] - 1;
		for (int j = 1; j <= n; ++j) {
			comb[i][j] = add(comb[i][j - 1], mul(comb[i][j - 1], mul(base++ - j + 1, modpow(j, M - 2))));
		}
	}

	dp[m - 1][0] = 1;
	for (int i = m - 1; i > 1; --i) {
		for (int j = 0; j <= n; ++j) {
			if (!dp[i][j])
				continue;
			for (int k = 0; j + k <= n; ++k) {
				if (k && (pt[i - 2] < l[j + k - 1] || pt[i - 2] >= r[j + k - 1]))
					break;
				dp[i - 1][j + k] = add(dp[i - 1][j + k], mul(dp[i][j], comb[i - 1][k]));
			}
		}
	}
	cout << mul(dp[1][n], modpow(tot, M - 2)) << '\n';
}