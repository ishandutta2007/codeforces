#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
using i64 = long long;
const int N = 3005, mod = 998244353;
int mul(int x, int y){ return i64(x) * y % mod; }
int add(int x, int y){ x += y; return x >= mod ? x - mod : x; }
int sub(int x,int y){ x += mod - y; return x >= mod ? x - mod : x; }
int fpow(int a, int t){
	int r = 1;
	for (; t; t >>= 1, a = mul(a, a)) if (t & 1) r = mul(r, a);
	return r;
}
int n, c, a[N], dp[N][N], res[N], cnt[N][N], pw[N], inv[N];
int main(){
	cin >> n >> c;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i], pw[i] = mul(pw[i - 1], 2) + 1;
		memcpy(cnt[i], cnt[i - 1], (c + 1) << 2);
		cnt[i][a[i]]++, inv[i] = fpow(pw[i], mod - 2);
	}
	if (c >= 10) {
		dp[0][0] = 1;
		for (int l = 0; l <= n; ++l) {
			int all_ways = pw[n - l] + 1;
			int color = 0;
			int ways = 1;
			for (int r = l + 1; r <= n; ++r) {
				int diff = cnt[r][a[r]] - cnt[l][a[r]];
				if (diff > 1) {
					ways = mul(ways, mul(pw[diff], inv[diff - 1]));
				} else {
					color++;
				}
				if (color == c) {
					int cur_ways = mul(ways, inv[diff]);
					all_ways = sub(all_ways, mul(cur_ways, pw[n - r] + 1));
					for (int k = 0; k * c <= l; ++k) {
						dp[r][k + 1] = add(dp[r][k + 1], mul(dp[l][k], cur_ways));
					}
				}
			}
			for (int k = 0; k * c <= l; ++k) {
				res[k] = add(res[k], mul(dp[l][k], all_ways));
			}
		}
	} else {
		int e = (1 << c) - 1;
		dp[0][0] = 1;
		for (int l = 1; l <= n; ++l) {
			int u = 1 << (a[l] - 1);
			for (int k = l / c; k >= 0; --k) {
				for (int s = e - 1; s >= 0; --s) {
					if (!dp[k][s]) continue;
					if (s + u != e) dp[k][s | u] = add(dp[k][s | u], dp[k][s]);
					else dp[k + 1][0] = add(dp[k + 1][0], dp[k][s]);
				}
			}
		}
		for (int k = 0; k <= n; ++k) for (int s = 0; s <= e; ++s) res[k] = add(res[k], dp[k][s]);
	}
	res[0] = sub(res[0], 1);
	for (int i = 0; i <= n; ++i) {
		cout << res[i] << " \n"[i == n];
	}
}