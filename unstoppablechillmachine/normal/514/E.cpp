#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

vector<vector<int>> one, ow;

vector<vector<int>> mult(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> c(101, vector<int>(101));
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				add(c[i][j], mult(a[i][k], b[k][j]));
			}
		}
	}
	return c;
}

vector<vector<int>> sum(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> c = a;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			add(c[i][j], b[i][j]);
		}
	}
	return c;
}

pair<vector<vector<int>>, vector<vector<int>>> b_pow(int n) {
	if (n == 1) {
		return {one, ow};
	}
	if (n & 1) {
		auto res = b_pow(n - 1);
		return {mult(one, res.F), sum(ow, mult(one, res.S))};
	}
	auto res = b_pow(n >> 1);
	return {mult(res.F, res.F), sum(res.S, mult(res.F, res.S))};
}

int slow_solve(vector<int> cnt, int x) {
	vector<int> dp(x + 1);
	dp[0] = 1;
	int ans = 1;
	for (int i = 1; i <= x; i++) {
		for (int j = i - 100; j < i; j++) {
			if (j >= 0) {
				add(dp[i], mult(dp[j], cnt[i - j]));
			}
		}
		add(ans, dp[i]);
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	vector<int> cnt(101);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	vector<int> dp(101);
	dp[0] = 1;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			add(dp[i], mult(dp[j], cnt[i - j]));
		}
	}
	if (x <= 100) {
		cout << slow_solve(cnt, x) << '\n';
		exit(0);
	}
	else {
		one.resize(101, vector<int>(101, 0));
		for (int i = 1; i <= 99; i++) {
			one[i + 1][i] = 1;
		}
		ow.resize(101, vector<int>(101, 0));
		for (int i = 1; i <= 100; i++) {
			ow[i][i] = 1;
		}
		for (int i = 1; i <= 100; i++) {
			one[i][100] = cnt[101 - i];
		}
		auto mt = b_pow(x - 100);
		int ans = 1;
		for (int i = 1; i <= 100; i++) {
			if (i < 100) {
				add(ans, dp[i]);
			}
			add(ans, mult(dp[i], mt.F[i][100]));
			add(ans, mult(dp[i], mt.S[i][100]));
		}
		cout << ans << '\n';
	}
}