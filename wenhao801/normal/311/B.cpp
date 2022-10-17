#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define int long long

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') t = -1, c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;

int n, m, p;

int dis[MAXN] = {};
int X[MAXN] = {};
int S[MAXN] = {};
int dp[101][MAXN] = {};
int q[MAXN] = {};

int cnty (int i, int j) { return dp[i - 1][j] + S[j]; }

signed main () {
	n = read(), m = read(), p = read();
	int i, j;
	for (i = 2; i <= n; i++) dis[i] = dis[i - 1] + read();
	for (i = 1; i <= m; i++) { int x = read(), y = read(); X[i] = y - dis[x]; }
	sort(X + 1, X + m + 1);
	for (i = 1; i <= m; i++) S[i] = S[i - 1] + X[i];
	int head = 1, tail = 1;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= p; i++) {
		head = 1, tail = 1;
		q[1] = 0;
		for (j = 1; j <= m; j++) {
			while (head < tail && (cnty(i, q[head + 1]) - cnty(i, q[head])) <= X[j] * (q[head + 1] - q[head])) head++;
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][q[head]] + X[j] * (j - q[head]) - (S[j] - S[q[head]]));
			while (head < tail && (cnty(i, q[tail]) - cnty(i, q[tail - 1])) * (j - q[tail]) >= (cnty(i, j) - cnty(i, q[tail])) * (q[tail] - q[tail - 1])) tail--;
			q[++tail] = j;
		}
	}
	printf("%lld\n", dp[p][m]);
	return 0;
}