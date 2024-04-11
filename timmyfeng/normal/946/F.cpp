#include <bits/stdc++.h> 
using namespace std;

using mat = vector<vector<int>>;
const int M = 1e9 + 7;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

mat mul(const mat& a, const mat& b) {
	int n = a.size();
	mat res(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			for (int j = 0; j < n; ++j) {
				res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return res;
}

vector<int> mul(const mat& a, const vector<int>& b) {
	int n = a.size();
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i] = add(res[i], mul(a[i][j], b[j]));
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	string s;
	cin >> n >> x >> s;

	vector<mat> gates(2, mat(n + 1, vector<int>(n + 1)));
	for (int i = 0; i <= n; ++i) {
		gates[0][i][i] = 1 + (!i || i == n);
		gates[1][i][i] = gates[0][i][i];
	}

	for (int i = 0; i < n; ++i) {
		gates[s[i] == '1'][i + 1][i] = 1;
	}

	for (int i = 2; i <= x; ++i) {
		gates.emplace_back(mul(gates[i - 2], gates[i - 1]));
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	cout << mul(gates[x], dp)[n] << '\n';
}