#include <iostream>
#include <cstdio>
#define maxn 5005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, l[maxn], s[maxn], c[maxn];
int f[maxn][maxn];//ij 
int calc(int x, int y)
{
	if(!x) return 0;
	return calc(x / 2, y + 1) + (x / 2) * c[y + 1];
}
int t[maxn];
void add(int x, int y)
{
	for (; x <= m; x += (x & (-x)))
	{
		t[x] = max(t[x], y);
	}
}
int que(int x)
{
	if(!x) return 0;
	int res = 0;
	for (; x; x -= (x & (-x)))
	{
		res = max(res, t[x]);
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &l[n - i + 1]);
	for (int i = 1; i <= n; i++) scanf("%d", &s[n - i + 1]);
	for (int i = 1; i <= n + m; i++) scanf("%d", &c[i]);
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 1; j < maxn; j++)
		{
			f[i][j] = -INF;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = n; j > 0; j--)
		{
			f[l[i]][j] = max(f[l[i]][j], f[l[i]][j - 1] - s[i] + c[l[i]]);
			if(j == 1) f[l[i]][j] = max(f[l[i]][j], que(l[i] - 1) - s[i] + c[l[i]]);
			if(f[l[i]][j] <= -INF / 2) continue;
			int now = j, val = f[l[i]][j], k; 
			for (k = l[i] + 1; k <= m; k++)
			{
				now /= 2;
				val += now * c[k];
				f[k][now] = max(f[k][now], val);
				if(!now)
				{
					add(k, val);
					break;
				}
			}
		}
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
//				printf("%d %d %d\n", j, k, f[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			ans = max(ans, f[j][i] + calc(i, j));
		}
	}
	printf("%d\n", ans);
	return 0;
}