#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 405
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, m;
char s[maxn][maxn];
int sum[maxn][maxn];
inline int calc(int l1, int r1, int l2, int r2)
{
	return sum[l2][r2] - sum[l1 - 1][r2] - sum[l2][r1 - 1] + sum[l1 - 1][r1 - 1];
}
void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
	} 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] - '0');
		}
	}
	int ans = n * n;
	for (int i = 2; i <= n; i++)
	{
		for (int j = i + 2; j < n; j++)
		{
			int mn = n * n;
			for (int k = 4; k <= m; k++)
			{
				int p = k - 3;
				int cnt = (j - i + 1) - calc(i, p, j, p) - 2 * p + calc(i - 1, 1, i - 1, p) +  calc(j + 1, 1, j + 1, p);
				cnt -= calc(i, 1, j, p);
				mn = min(mn, cnt);
				ans = min(ans, mn + (j - i + 1) - calc(i, k, j, k) + calc(i, 1, j, k - 1) + 2 * (k - 1) - calc(i - 1, 1, i - 1, k - 1) - calc(j + 1, 1, j + 1, k - 1));
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{ 
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}