#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int T, n, k, cnt[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i <= 30; i++) cnt[i] = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1, x; i <= n; i++)
		{
			scanf("%d", &x);
			for (int j = 30; j >= 0; j--)
				cnt[j] += (x >> j) & 1;
		}
		int ans = 0;
		for (int i = 30; i >= 0; i--)
			if (k >= n - cnt[i])
				k -= n - cnt[i], ans += 1 << i;
		printf("%d\n", ans);
	}
	return 0;
}