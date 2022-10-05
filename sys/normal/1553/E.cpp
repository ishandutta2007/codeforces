#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int T, n, m, ct, x[Maxn], fa[Maxn], cnt[Maxn], ans[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
			x[i]--;
			cnt[(i - x[i] + n) % n]++;
		}
		for (int i = 0; i < n; i++)
			if (cnt[i] + 2 * m >= n)
			{
				int tmp = 0;
				for (int j = 0; j < n; j++)
					fa[j] = j;
				for (int j = 0; j < n; j++)
					if (get_fa(x[j]) != get_fa((j - i + n) % n)) tmp++, fa[get_fa((j - i + n) % n)] = get_fa(x[j]);
				if (tmp <= m)
					ans[++ct] = i;
			}
		printf("%d ", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}