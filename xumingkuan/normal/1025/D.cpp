#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 707;
int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
int n, a[MAXN];
bool e[MAXN][MAXN];
bool f[MAXN][MAXN][2];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		e[0][i] = e[i][0] = e[n + 1][i] = e[i][n + 1] = true;
		for(int j = 1; j < i; j++)
			e[i][j] = e[j][i] = (gcd(a[i], a[j]) > 1);
	}
	for(int i = n; i >= 1; i--)
	{
		f[i][i][0] = e[i][i - 1];//l
		f[i][i][1] = e[i][i + 1];//r
		for(int j = i + 1; j <= n; j++)
		{
			f[i][j][0] = (e[i - 1][j] && f[i][j - 1][1]) || (e[i][i - 1] && f[i + 1][j][0]);
			for(int k = i + 1; k < j && !f[i][j][0]; k++)
				f[i][j][0] = e[i - 1][k] && f[i][k - 1][1] && f[k + 1][j][0];
			f[i][j][1] = (e[j + 1][j] && f[i][j - 1][1]) || (e[i][j + 1] && f[i + 1][j][0]);
			for(int k = i + 1; k < j && !f[i][j][1]; k++)
				f[i][j][1] = e[j + 1][k] && f[i][k - 1][1] && f[k + 1][j][0];
		}
	}
	printf("%s\n", f[1][n][0] ? "Yes" : "No");
	return 0;
}