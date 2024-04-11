#include <iostream>
#include <cstdio>
#include <map>
#define maxn 2005
#define uint unsigned int
using namespace std;
const int mo = 1e9 + 7;
int n, m;
char s[maxn][maxn];
int dwn[maxn][maxn], rgh[maxn][maxn];
int f[maxn][maxn][2], sum[maxn][maxn][2];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	} 
	if(n == 1 && m == 1)
	{
		printf("1\n");
		return 0;
	} 
	for (int i = 1; i <= n; i++)
	{
		rgh[i][m + 1] = 0;
		for (int j = m; j >= 1; j--)
		{
			rgh[i][j] = rgh[i][j + 1] + (s[i][j] == 'R' ? 1 : 0);
		} 
	}
	for (int i = 1; i <= m; i++)
	{
		dwn[n + 1][i] = 0;
		for (int j = n; j >= 1; j--)
		{
			dwn[j][i] = dwn[j + 1][i] + (s[j][i] == 'R' ? 1 : 0);
		} 
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			dwn[i][j] = (n - i) - dwn[i + 1][j];
			rgh[i][j] = (m - j) - rgh[i][j + 1];
//			printf("%d %d %d %d\n", i, j, dwn[i][j], rgh[i][j]);
		}
	}
//	printf("\n");
	f[n][m][0] = f[n][m][1] = sum[n][m][0] = sum[n][m][1] = 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if(i == n && j == m) continue;
			f[i][j][0] = (sum[i][j + 1][1] - sum[i][j + rgh[i][j] + 1][1] + mo) % mo;
			f[i][j][1] = (sum[i + 1][j][0] - sum[i + dwn[i][j] + 1][j][0] + mo) % mo;
			sum[i][j][0] = (sum[i + 1][j][0] + f[i][j][0]) % mo;
			sum[i][j][1] = (sum[i][j + 1][1] + f[i][j][1]) % mo;
//			printf("%d %d %d %d\n", i, j, f[i][j][0], f[i][j][1]);
		}
	}
	printf("%d", (f[1][1][0] + f[1][1][1]) % mo);
	return 0;
}