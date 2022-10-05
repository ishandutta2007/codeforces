#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, k, a[Maxn], sum[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		pair <int, int> ans = make_pair(0, 0x3f3f3f3f);
		scanf("%d%d", &n, &k);
		memset(sum, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum[a[i]]++;
		int pt = 1;
		for (int i = 1; i <= n; i++)
		{
			sum[i] += sum[i - 1];
			while (pt <= i && sum[i] - sum[pt] >= (n + k + 1) / 2) pt++;
			if (sum[i] - sum[pt - 1] >= (n + k + 1) / 2 && i - pt < ans.second - ans.first) ans = make_pair(pt, i);
		}
		printf("%d %d\n", ans.first, ans.second);
		if (k == 1) printf("%d %d\n", 1, n);
		else
		{
			int las = 1, ct = 0;
			for (int i = 1; i <= n; i++)
			{
				if (ans.first <= a[i] && a[i] <= ans.second) ct++;
				else ct--;
				if (ct == 1)
				{
					printf("%d %d\n", las, i), las = i + 1, k--, ct = 0;
					if (k == 1)
					{
						printf("%d %d\n", i + 1, n);
						break;
					}
				}
			}
		}
	}
	return 0;
}