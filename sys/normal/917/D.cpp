#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105, p = 1e9 + 7;
int n, x[Maxn], y[Maxn];
map <pair <int, int>, bool> Ma;
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
struct Matrix
{
	long long val[Maxn][Maxn];
	Matrix()
	{
		memset(val, 0, sizeof(val));
	}
	void clear(void)
	{
		memset(val, 0, sizeof(val));
	}
	long long cal(void)
	{
		Matrix tmp = *this;
		for (int i = 1; i < n; i++)
		{
			long long inv = fast_pow(tmp.val[i][i], p - 2);
			for (int j = i + 1; j < n; j++)
				(tmp.val[i][j] *= inv) %= p;
			for (int j = 1; j < n; j++)
				if (i != j)
					for (int k = n - 1; k >= i; k--)
						((tmp.val[j][k] -= tmp.val[j][i] * tmp.val[i][k] % p) += p) %= p;
		}
		long long ans = 1;
		for (int i = 1; i < n; i++)
			(ans *= tmp.val[i][i]) %= p;
		return ans;
	}
	void work(void)
	{
		for (int i = 1; i <= n; i++)
		{
			long long inv = fast_pow(val[i][i], p - 2);
			for (int j = i; j <= n + 1; j++)
				(val[i][j] *= inv) %= p;
			for (int j = 1; j <= n; j++)
				if (i != j)
					for (int k = n + 1; k >= i; k--)
						((val[j][k] -= val[j][i] * val[i][k] % p) += p) %= p;
		}
	}
} G, now;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d%d", &x[i], &y[i]), Ma[make_pair(x[i], y[i])] = Ma[make_pair(y[i], x[i])] = true;
	for (int i = 1; i <= n; i++)
	{
		G.clear();
		for (int j = 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				if (!Ma[make_pair(j, k)])
				{
					G.val[j][k]--, G.val[k][j]--;
					G.val[j][j]++, G.val[k][k]++;
				}
				else
				{
					G.val[j][k] -= i, G.val[k][j] -= i;
					G.val[j][j] += i, G.val[k][k] += i;
				}
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				G.val[j][k] = (G.val[j][k] % p + p) % p;
		now.val[i][1] = 1;
		for (int j = 2; j <= n; j++)
			now.val[i][j] = now.val[i][j - 1] * i % p;
		now.val[i][n + 1] = G.cal();
	}
	now.work();
	for (int i = 1; i <= n; i++)
		printf("%lld ", now.val[i][n + 1]);
	return 0;
}