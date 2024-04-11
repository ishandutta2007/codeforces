#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 20 | 5;
int n, k, b[Maxn], len[Maxn], val[Maxn][21];
bool ans[Maxn], pre[Maxn], suf[Maxn], sum[24][Maxn];
bool C(int x, int y)
{
	for (int i = 0; i < 30; i++)
		if ((x >> i & 1) < (y >> i & 1)) return true;
	return false;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 23; i++)
		for (int j = 0; j <= n - i; j++)
			sum[i][j] = (j ? sum[i][j - 1] : 0) ^ C(n - i, j) ^ 1;
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
	{
		len[i] = 20;
		val[i][0] = b[i];
		for (int j = 1; j <= 20; j++)
		{
			if (i + j > n || b[i + j] > 20 || val[i][j - 1] * (1LL << b[i + j]) > (1 << 20))
			{
				len[i] = j - 1;
				break;
			}
			val[i][j] = val[i][j - 1] * (1 << b[i + j]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= len[i]; j++)
			if (i + j <= n)
			{
				int c = 1 + (i != 1) + (i + j != n);
				ans[val[i][j]] ^= n - j - 1 >= k && ((k < c ? 0 : sum[j + c][k - c]) ^ (n - c - j < 0 ? 0 : sum[j + c][n - c - j]));
			}
	bool flag = false;
	for (int i = (1 << 20) - 1; i >= 0; i--)
		if (flag || ans[i]) putchar(ans[i] + '0'), flag |= ans[i];
	if (!flag) putchar('0');
	return 0;
}