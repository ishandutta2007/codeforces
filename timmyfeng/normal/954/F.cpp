#include <bits/stdc++.h> 
using namespace std;

using mat = vector<vector<int>>;
using ll = long long;

const int M = 1e9 + 7;

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (ll)a * b % M;
}

mat mul(mat a, mat b) {
	mat res(3, vector<int>(3));
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			for (int j = 0; j < 3; ++j) {
				res[i][j] = add(res[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return res;
}

vector<int> mul(mat a, vector<int> v) {
	vector<int> res(3);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			res[i] = add(res[i], mul(a[i][j], v[j]));
		}
	}
	return res;
}

mat mat_pow(mat a, ll e) {
	mat res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	while (e) {
		if (e % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		e /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<mat> gate(1 << 3, mat(3, vector<int>(3)));
	for (int mask = 0; mask < (1 << 3); ++mask) {
		for (int i = 0; i < 3; ++i) {
			if (mask & (1 << i)) {
				for (int j = max(0, i - 1); j <= min(2, i + 1); ++j) {
					gate[mask][i][j] = 1;
				}
			}
		}
	}

	int n;
	ll m;
	cin >> n >> m;

	vector<tuple<ll, int, int>> events;
	for (int i = 0; i < n; ++i) {
		int a;
		ll l, r;
		cin >> a >> l >> r;
		events.emplace_back(l, a - 1, 1);
		events.emplace_back(r + 1, a - 1, -1);
	}
	events.emplace_back(m + 1, 0, 0);
	sort(events.begin(), events.end());

	ll cur = 1;
	int mask = 7;
	vector<int> dp(3);
	vector<int> cnt(3);
	dp[1] = 1;

	for (auto e : events) {
		ll i;
		int j, type;
		tie(i, j, type) = e;

		dp = mul(mat_pow(gate[mask], i - cur - 1), dp);
		cur = i - 1;

		cnt[j] += type;
		if (!cnt[j]) {
			mask |= 1 << j;
		} else {
			mask &= ~(1 << j);
		}
	}

	cout << dp[1] << '\n';
}