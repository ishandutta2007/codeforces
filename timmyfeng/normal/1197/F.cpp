#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using mat = vector<vector<ll>>;
const int MX = 1e3;
const int M = (119 << 23) + 1;

vector<pair<int, int>> acc[MX + 1];
mat pows[30], colm[3];
bool valid[3][3];
ll dp[MX + 1][4];
int a[MX + 1];

int add(int a, int b) {
	return a + b > M ? a + b - M : a + b;
}

int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

mat add(mat& a, mat& b) {
	int n = a.size();
	int m = a[0].size();
	mat res(n, vector<ll>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			res[i][j] = add(a[i][j], b[i][j]);
		}
	}
	return res;
}

mat mul(mat& a, mat& b) {
	int n = a.size();
	int m = b.size();
	int p = b[0].size();
	mat res(n, vector<ll>(p));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < p; ++k) {
				res[i][k] = add(res[i][k], mul(a[i][j], b[j][k]));
			}
		}
	}
	return res;
}

vector<ll> mul(mat& a, vector<ll>& b) {
	int n = a.size();
	vector<ll> res(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			res[i] = add(res[i], mul(b[j], a[i][j]));
		}
	}
	return res;
}

void matpow(int a, vector<ll>& b) {
	for (int i = 0; i < 30; ++i) {
		if (a & (1 << i)) {
			b = mul(pows[i], b);
		}
	}
}

int mex(int a, int col) {
	int tmp = (a << 2) & ((1 << 6) - 1);
	int ma = (1 << 4) - 1;
	for (int i = 0; i < 3; ++i) {
		if (valid[col][i]) {
			ma &= ~(1 << (a % 4));
		}
		a /= 4;
	}
	return __builtin_ctz(ma) + tmp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	while (m--) {
		int x, y, c;
		cin >> x >> y >> c;
		acc[x].emplace_back(y, c - 1);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> valid[i][j];
		}
	}

	fill(colm, colm + 3, mat(64, vector<ll>(64)));
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 3; ++j) {
			++colm[j][mex(i, j)][i];
		}
	}
	pows[0] = add(colm[0], colm[1]); 
	pows[0] = add(pows[0], colm[2]);
	for (int i = 1; i < 30; ++i) {
		pows[i] = mul(pows[i - 1], pows[i - 1]);
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		vector<ll> cur(64);
		cur[63] = 1;
		int prev = 0;
		sort(acc[i].begin(), acc[i].end());
		for (auto [x, c] : acc[i]) {
			matpow(x - prev - 1, cur);
			cur = mul(colm[c], cur);
			prev = x;
		}
		matpow(a[i] - prev, cur);

		vector<ll> freq(4);
		for (int j = 0; j < 64; ++j) {
			freq[j % 4] = add(freq[j % 4], cur[j]);
		}
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				dp[i][j ^ k] = add(dp[i][j ^ k], mul(freq[j], dp[i - 1][k]));
			}
		}
	}
	cout << dp[n][0] << '\n';
}