#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
int tot;
long long pos[Maxn], f[7][Maxn];
int main()
{
	for (int i = 1; i <= 10000; i++)
		f[1][i] = i;
	for (int i = 2; i <= 5; i++)
	{
		for (int j = 1; j <= 10000; j++)
		{
			f[i][j] = f[i - 1][j];
			long long now = min(10000LL, j + f[i - 1][j] + 1);
			for (int k = 1; k <= j; k++)
			{
				if (now == 10000)
				{
					f[i][j] += (f[i - 1][10000] + 1) * (j - k + 1);
					break;
				}
				f[i][j] += f[i - 1][min(10000LL, now)] + 1;
				now = min(10000LL, now + f[i - 1][now] + 1);
			}
		}
	}
	long long now = 1;
	for (int j = 5; j >= 1; j--)
	{
		tot = 0;
		pos[0] = now - 1;
		for (int i = min(now, 10000LL); i >= 1; i--)
		{
			now += f[j - 1][min(now, 10000LL)];
			pos[++tot] = now;
			now++;
		}
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i++)
			printf("%lld ", pos[i]);
		puts("");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x == -1) return 0;
		now = pos[x] + 1;
	}
	return 0;
}