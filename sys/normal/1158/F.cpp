#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 3005, p = 998244353;
int n, c, m, a[Maxn];
namespace Subtask1
{
	int zero, cnt[Maxn], ct[Maxn][Maxn], sum[Maxn / 10][Maxn];
	long long p2[Maxn], f[Maxn / 10][Maxn];
	long long get_inv(int x)
	{
		if (x <= 1) return 1;
		return (p - p / x) * get_inv(p % x) % p;
	}
	void work(void)
	{
		p2[0] = 1;
		for (int i = 1; i <= n; i++)
			p2[i] = p2[i - 1] * 2 % p;
		for (int i = 1; i <= n; i++)
		{
			memset(cnt, 0, sizeof(int) * (n + 1));
			long long prod = 1;
			zero = c;
			for (int j = i; j <= n; j++)
			{
				if (!cnt[a[j]]) zero--;
				else (prod *= get_inv(p2[cnt[a[j]]] - 1)) %= p;
				cnt[a[j]]++;
				(prod *= p2[cnt[a[j]]] - 1) %= p;
				if (i == j || a[i] != a[j])
					ct[i][j] = (zero ? 0 : prod) * get_inv(p2[cnt[a[j]]] - 1) % p * get_inv(p2[cnt[a[i]]] - 1) % p * p2[cnt[a[j]] - 1] % p;
			}
		}
		f[0][0] = sum[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= i; k++)
				for (int j = 1; j <= m; j++)
				{
					f[j][i] = (f[j][i] + 1ll * sum[j - 1][k - 1] * ct[k][i]) % p;
					if (!sum[j - 1][k - 1]) break;
				}
			f[0][i] = p2[i - 1];
			for (int j = 0; j <= m; j++)
				sum[j][i] = (sum[j][i - 1] + f[j][i]) % p;
		}
		for (int i = 0; i <= n; i++)
			printf("%d ", i <= m ? (sum[i][n] - sum[i + 1][n] - !i + p) % p : 0);
	}
}
namespace Subtask2
{
	int f[Maxn][Maxn], g[Maxn][Maxn];
	void work(void)
	{
		int S = (1 << c) - 1;
		f[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
				for (int k = 0; k <= S; k++)
					g[j][k] = f[j][k];
			int s = 1 << (a[i] - 1);
			for (int j = m; j >= 0; j--)
			{
				for (int k = 0; k <= S; k++)
					(f[j][k | s] += g[j][k]) %= p;
				(f[j + 1][0] += f[j][S]) %= p, f[j][S] = 0;
			}
		}
		for (int i = 0; i <= n; i++)
		{
			long long tmp = 0;
			for (int j = 0; j <= S; j++)
				(tmp += f[i][j]) %= p;
			printf("%lld ", tmp - !i);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &c);
	m = n / c;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (c >= 11)
		return Subtask1::work(), 0;
	return Subtask2::work(), 0;
}