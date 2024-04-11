#include <bits/stdc++.h>
using namespace std;
int nums[25];
int ed, g[256], f[256], d[256], dp[12][256];
int dfs(int i, int u, int s) {
	if (i == -1) return ed == s;
	if (!u && dp[i][s] != -1) return dp[i][s];
	int maxv = u ? nums[i] : 6, ret = 0;
	for (int j = 0; j <= maxv; ++j)
		if ((s & (1 << j)) == 0) 
			ret += dfs(i - 1, u && (j == maxv), s | (1 << j));
	return u ? ret : dp[i][s] = ret;
}
void solve(int n) {
	--n;
	int len = 0;
	if (!n) len = 1,nums[0] = 0;
	while (n) {
		nums[len++] = n % 7;
		n /= 7;
	}
	
	for (int i = 0; i < 256; ++i) {
		memset(dp, 255, sizeof dp);
		ed = i;
		f[i] = dfs(len - 1, 1, 0);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	solve(n);
	memcpy(g, f, sizeof f);
	solve(m);
	long long ans = 0;
	for (int i = 0; i < 256; ++i) 
		for (int j = i; j; j = (j - 1) & i)
			d[i] += f[j];
	
	for (int i = 0; i < 256; ++i)
		ans += 1LL * g[i] * d[255 ^ i];
	cout << ans << endl;
}