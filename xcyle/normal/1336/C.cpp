#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 3005
using namespace std;
const int mo = 998244353;
int n, m;
char s[maxn], t[maxn];
int f[maxn][maxn], g[maxn][maxn], pow[maxn];
int main()
{
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	pow[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if(t[i] == s[1]) f[i][i] = 2;
		pow[i] = pow[i - 1] * 2 % mo;
	}
	for (int len = 2; len <= m; len++)
	{
		for (int i = 1; i + len - 1 <= m; i++)
		{
			int j = i + len - 1;
			if(s[len] == t[i]) f[i][j] = (f[i][j] + f[i + 1][j]) % mo;
			if(s[len] == t[j]) f[i][j] = (f[i][j] + f[i][j - 1]) % mo;
//			printf("%d %d %d\n", i, j, f[i][j]);
		}
	}
	g[n + 1][0] = 1;
	for (int i = n; i >= 1; i--)
	{
		g[i][0] = g[i + 1][0] + 1;
		for (int j = 1; j <= m; j++)
		{
			g[i][j] = g[i + 1][j];
			if(s[i] == t[j]) g[i][j] = (g[i][j] + g[i + 1][j - 1]) % mo;
		}
	}
	int ans = 0;
	for (int i = 1; i < m; i++)//sif 
	{
		ans = (ans + (ll)f[m - i + 1][m] * g[i + 2][m - i] % mo) % mo;
	}
	ans = (ans + (ll)f[1][m] * (n - m + 1) % mo) % mo;
//	printf("%d\n", ans); 
	for (int i = 2; i <= n; i++)//i-1i
	{
		if(s[i] == t[m]) ans = (ans + (ll)g[i + 1][m - 1] * pow[i - 1] % mo) % mo;
	}
	printf("%d", ans);
	return 0;
}