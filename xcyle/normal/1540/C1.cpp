#include <iostream>
#include <cstdio>
#define maxn 105
using namespace std;
const int mo = 1e9 + 7;
int n, f[maxn][maxn * maxn];
int b[maxn], c[maxn], q, x;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) scanf("%d", &b[i]);
	scanf("%d", &q);
	scanf("%d", &x);
	f[0][0] = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int t = i * x;
		for (int j = 1; j < i; j++) t +=  b[j] * (i - j);
//		printf("%d ", t);
		for (int j = max(0, t); j <= n * 100; j++)
		{
			for (int k = 0; k <= c[i]; k++)
			{
				if(j - k >= 0) f[i][j] = (f[i][j] + f[i - 1][j - k]) % mo;
			}
			if(i == n) ans = (ans + f[i][j]) % mo;
		}
	}
	printf("%d", ans);
	return 0;
}