#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int mult(int x, int y)
{
	return ((long long)x * y) % MOD;
}

const int N = 2020;
const int M = 100100;
int n, m;
char s[M];
int dp[N][N];

int main()
{
	dp[0][0] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 0; j <= i; j++)
			dp[i][j] = add(j < i ? dp[i - 1][j + 1] : 0, j > 0 ? dp[i - 1][j - 1] : 0);
	
	scanf("%d%d", &n, &m);
	scanf(" %s ", s);
	int minBal = 0, bal = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == '(')
			bal++;
		else
			bal--;
		minBal = min(minBal, bal);
	}
	minBal *= -1;
	n -= m;
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = minBal; j <= i; j++)
		{
			int x = j + bal;
			int r = n - i;
			if (r < x) continue;
			ans = add(ans, mult(dp[i][j], dp[r][x]));
		}
	printf("%d\n", ans);

	return 0;
}