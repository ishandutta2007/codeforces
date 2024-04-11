#include <bits/stdc++.h>
using namespace std;

const int Maxn = 65;
int l;
long long s, ans, f[Maxn][2 * Maxn][2];
int main()
{
	scanf("%lld", &s);
	l = 1;
	while ((1LL << (l + 1)) - 1 <= s) l++;
	for (int i = 1; i <= l; i++)
	{
		long long x = s / ((1LL << i) - 1);
		long long ret = s - x * ((1LL << i) - 1);
		for (int j = i - 1; j >= 1; j--)
			if (ret >= (1LL << j) - 1) ret -= (1LL << j) - 1;
		if (!ret) ans++;
	}
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= l; j++)
		{
			if ((1LL << (i + 1)) + (1LL << (j + 1)) - 3 > s - ((1LL << j) - 1))
				break;
			long long x = (s - ((1LL << j) - 1)) / ((1LL << (i + 1)) + (1LL << (j + 1)) - 3);
			long long ret = s - ((1LL << j) - 1) - x * ((1LL << (i + 1)) + (1LL << (j + 1)) - 3);
			for (int k = 0; k <= i + j - 2; k++)
			{
				if ((ret + k) & 1) continue;
				long long tmp_ret = (ret + k) >> 1;
				memset(f, 0, sizeof(f));
				f[0][0][0] = 1;
				int limit = 60;
				while (limit && !(tmp_ret >> (limit - 1))) limit--;
				for (int p = 1; p <= limit; p++)
					for (int q = 0; q <= 2 * (p - 1); q++)
						for (int a = 0; a <= (p < i); a++)
							for (int b = 0; b <= (p < j); b++)
							{
								bool c = (((a + b) & 1) != ((tmp_ret >> (p - 1)) & 1));
								f[p][q + a + b][(a + b + c) / 2] += f[p - 1][q][c];
							}
				ans += f[limit][k][0];
			}
		}
	printf("%lld", ans);
	return 0;
}