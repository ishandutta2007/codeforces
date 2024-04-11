#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, k, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (k == 1)
		{
			printf("%d\n", (n - 1) / 2);
			continue;
		}
		for (int i = 2; i < n; i++)
			if (a[i] > a[i - 1] + a[i + 1])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}