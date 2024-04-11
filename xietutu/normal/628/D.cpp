#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005, MOD = 1e9+7;
int mod, m, d, num[maxn], dp[maxn][maxn][2][2];
char a[maxn], b[maxn];
int dfs(int i, int j, int u, int f, int e) {
	if (i == -1) return j == 0;
	if (!u && dp[i][j][f][e] != -1) return dp[i][j][f][e];
	int ret = 0, m = u ? num[i] : 9;
	for (int k = 0; k <= m; ++k)
		if (f) {
			if (k == 0) ret = (ret + dfs(i - 1, j * 10 % mod, u && (k == m), 1, e)) % MOD;
			else if (k != d) ret = (ret + dfs(i - 1, (j * 10 + k) % mod, u && (k == m), 0, 0)) % MOD; 
		}
		else if ((k == d && !e) || (k != d && e)) ret = (ret + dfs(i - 1, (j * 10 + k) % mod, u && (k == m), 0, e ^ 1)) % MOD;
	return u ? ret : dp[i][j][f][e] = ret;
}
int calc(char* s) {
	m = strlen(s);
	for (int i = 0; i < m; ++i)
		num[i] = s[m - i - 1] - '0';
	return dfs(m - 1, 0, 1, 1, 1);
}
bool check(char* s) {
	m = strlen(s);
	int ret = 0;
	for (int i = 0; i < m; ++i) { 
		int t = s[i] - '0';
		if (i % 2 == 0 && t == d) return false;
		if (i % 2 != 0 && t != d) return false;
		ret = (ret * 10 + t) % mod;
	}
	return ret == 0;
}
int main() {
	scanf("%d%d", &mod, &d);
	scanf("%s", a);
	scanf("%s", b);
	memset(dp, 255, sizeof dp);
	printf("%d\n", ((calc(b) - calc(a)) % MOD + check(a) + MOD) % MOD);
}