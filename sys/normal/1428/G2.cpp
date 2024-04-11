#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int k, q, pnt, head, tail, Qu[Maxn];
long long f[Maxn], g[Maxn], v[Maxn];
int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= 6; i++)
		scanf("%lld", &v[i]);
	int now = 3;
	for (int i = 0; i <= 999999; i++)
	{
		int tmp = i;
		for (int j = 1; j <= 6; j++)
		{
			if (tmp % 10 == 3) f[i] += v[j];
			if (tmp % 10 == 6) f[i] += 2 * v[j];
			if (tmp % 10 == 9) f[i] += 3 * v[j];
			tmp /= 10;
		}
	}
	for (int i = 1; i <= 6; i++)
	{
		for (int q = 0; q < now; q++)
		{
			head = 1, tail = 0;
			Qu[1] = 0;
			for (int j = q; j <= 999999; j += now)
			{
				while (head <= tail && Qu[head] < j - now * 3 * (k - 1LL)) head++;
				if (head <= tail) g[j] = f[Qu[head]] + (j - Qu[head]) / now * v[i];
				while (head <= tail && f[j] - j / now * v[i] > f[Qu[tail]] - Qu[tail] / now * v[i]) tail--;
				Qu[++tail] = j;
			}
		}
		for (int j = 0; j <= 999999; j++) f[j] = max(f[j], g[j]);
		now *= 10;
	}
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		printf("%lld\n", f[x]);
	}
	return 0;
}