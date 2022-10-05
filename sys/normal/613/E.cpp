#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005, p = 1e9 + 7;
int n, m, lcs[2][2][Maxn][Maxn], lcp[2][2][Maxn][Maxn], f[2][Maxn][Maxn], g[2][Maxn][Maxn];
bool mat[2][2][Maxn][Maxn];
long long ans;
char str[2][Maxn], T[Maxn];
void work(void)
{
	for (int i = 1; i <= m; i++)
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 1; k <= n; k++)
				lcs[0][j][k][i] = (str[j][k] == T[i]) ? lcs[0][j][k - 1][i - 1] + 1 : 0;
			for (int k = n; k >= 1; k--)
				lcs[1][j][k][i] = (str[j][k] == T[i]) ? lcs[1][j][k + 1][i - 1] + 1 : 0;
		}
	for (int i = m; i >= 1; i--)
		for (int j = 0; j <= 1; j++)
		{
			for (int k = 1; k <= n; k++)
				lcp[0][j][k][i] = (str[j][k] == T[i]) ? lcp[0][j][k - 1][i + 1] + 1 : 0;
			for (int k = n; k >= 1; k--)
				lcp[1][j][k][i] = (str[j][k] == T[i]) ? lcp[1][j][k + 1][i + 1] + 1 : 0;
		}
	for (int i = 0; i <= 1; i++)
		for (int j = 1; j <= n; j++)
		{
			for (int k = 2; k <= min(j, m / 2); k++)
				mat[0][i][j][k] = lcp[0][i ^ 1][j][1] >= k && lcp[1][i][j - k + 1][k + 1] >= k;
			for (int k = 2; k <= min(n - j + 1, m / 2); k++)
				mat[1][i][j][k] = lcs[1][i ^ 1][j][m] >= k && lcs[0][i][j + k - 1][m - k] >= k;
		}
	if (m % 2 == 0)
	{
		for (int j = 1; j <= n; j++)
			ans += (int) mat[0][1][j][m / 2] + mat[1][1][j][m / 2];
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 2; k <= m / 2 - 2; k++)
					ans += (mat[0][i][j][k] & mat[1][i][j + 1][m / 2 - k]);
	}
	for (int j = 1; j <= n; j++)
	{
		for (int i = 0; i <= 1; i++)
		{
			if (str[i][j] == T[1]) f[i][j][1]++;
			for (int k = 2; k <= m / 2; k++)
				if (mat[0][i][j - 1][k] && str[i][j] == T[2 * k + 1]) f[i][j][2 * k + 1]++;
			for (int k = 1; k < m; k++)
				if (str[i][j] == T[k + 1]) f[i][j][k + 1] = ((long long) f[i][j][k + 1] + f[i][j - 1][k] + g[i][j - 1][k]) % p;
			for (int k = 1; k < m; k++)
				if (str[i ^ 1][j] == T[k + 1]) (g[i ^ 1][j][k + 1] += f[i][j][k]) %= p;
		}
		for (int i = 0; i <= 1; i++)
		{
			(ans += f[i][j][m] + g[i][j][m]) %= p;
			for (int k = 2; k <= m / 2; k++)
				if (mat[1][i][j + 1][k]) (ans += f[i][j][m - 2 * k] + g[i][j][m - 2 * k]) %= p;
		}
	}
}
void dfs(int x, int y, int d)
{
	if (str[x][y] != T[d]) return ;
	if (d == m)
	{
		ans++;
		return ;
	}
	if (x == 1) dfs(0, y, d + 1);
	else dfs(1, y, d + 1);
	if (y != 1) dfs(x, y - 1, d + 1);
	if (y != n) dfs(x, y + 1, d + 1);
}
int main()
{
	scanf("%s%s%s", str[0] + 1, str[1] + 1, T + 1);
	n = strlen(str[0] + 1), m = strlen(T + 1);
	if (m <= 2)
	{
		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				dfs(i, j, 1);
	}
	else
	{
		work();
		reverse(T + 1, T + 1 + m);
		memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
		work();
	}
	printf("%lld", ans);
	return 0;
}