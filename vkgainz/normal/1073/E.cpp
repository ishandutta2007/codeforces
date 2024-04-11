#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<long long, int> pt;

const int N = 20;
const int M = 1 << 10;
const int MOD = 998244353;

int k;
int pw10[N];
int bitCnt[M];

pt dp[N][M][2];

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int calc(const string &s) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			dp[i][j][0] = dp[i][j][1] = { 0ll, 0 };
		}
	}
	
	int len = s.size();
	dp[0][0][1] = { 1ll, 0 };
	for (int i = 0; i < len; ++i) {
		int cdig = s[i] - '0';
		for (int mask = 0; mask < M; ++mask) {
			if (dp[i][mask][0].x == 0 && dp[i][mask][1].x == 0) continue;
			for (int dig = (i == 0); dig <= 9; ++dig) {
				int nmask = mask | (1 << dig);
				long long cnt = dp[i][mask][0].x;
				int sum = add(dp[i][mask][0].y, mul(dig, mul(pw10[len - i - 1], cnt % MOD)));
				dp[i + 1][nmask][0].x += cnt;
				dp[i + 1][nmask][0].y = add(dp[i + 1][nmask][0].y, sum);
			}
			
			for (int dig = (i == 0); dig <= cdig; ++dig) {
				int nmask = mask | (1 << dig);
				long long cnt = dp[i][mask][1].x;
				int sum = add(dp[i][mask][1].y, mul(dig, mul(pw10[len - i - 1], cnt % MOD)));
				dp[i + 1][nmask][dig == cdig].x += cnt;
				dp[i + 1][nmask][dig == cdig].y = add(dp[i + 1][nmask][dig == cdig].y, sum);
			}
		}
	}
	
	int ans = 0;
	for (int mask = 0; mask < M; ++mask) {
		if (bitCnt[mask] > k) continue;
		ans = add(ans, dp[len][mask][0].y);
		ans = add(ans, dp[len][mask][1].y);
	}
	return ans;
}

int calc(long long n) {
	int len = to_string(n).size();
	int ans = 0;
	for (int l = 1; l < len; ++l) {
		ans = add(ans, calc(string(l, '9')));
	}
	ans = add(ans, calc(to_string(n)));
	return ans;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	pw10[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw10[i] = mul(pw10[i - 1], 10);
	}
	for (int i = 0; i < M; ++i) {
		bitCnt[i] = __builtin_popcount(i);
	}
	
	long long l, r;
	cin >> l >> r >> k;
	int ans = add(calc(r), -calc(l - 1));
	cout << ans << endl;
	
	return 0;
}