#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
int T, n, ct, a[Maxn], b[Maxn];
bool f[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d", &n);
		n <<= 1;
		memset(f, false, sizeof(bool[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int now = 1;
		a[n + 1] = 0x3f3f3f3f;
		while (now != n + 1)
		{
			for (int j = now + 1; j <= n + 1; j++)
				if (a[j] > a[now])
				{
					b[++ct] = j - now, now = j;
					break;
				}
		}
		f[0] = true;
		for (int i = 1; i <= ct; i++)
			for (int j = n; j >= b[i]; j--)
				f[j] |= f[j - b[i]];
		printf(f[n / 2] ? "YES\n" : "NO\n");
	}
	return 0;
}