#include <bits/stdc++.h>
using namespace std;

using mat = vector<vector<int>>;
using ll = long long;
const int LOG = 60;
const int M = 1e9 + 7;

int add(int a, int b) {
	int res = a + b;
	return res < M ? res : res - M;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

mat mul(const mat& a, const mat& b) {
	int n = a.size();
	mat res(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return move(res);
}

vector<int> mul(const mat& a, const vector<int>& b) {
	int n = a.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i] = add(res[i], mul(a[i][j], b[j]));
		}
	}
	return move(res);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;

	mat pows(m, vector<int>(m));
	for (int i = 0; i + 1 < m; ++i) {
		pows[i][i + 1] = 1;
	}
	pows[m - 1][0] = pows[m - 1][m - 1] = 1;

	vector<int> vec(m);
	vec[m - 1] = 1;
	for (int i = 0; i < LOG; ++i) {
		if (i) {
			pows = mul(pows, pows);
		}
		if (n & (1LL << i)) {
			vec = mul(pows, vec);
		}
	}
	cout << vec[m - 1] << '\n';
}