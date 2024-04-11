#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		long long sum = 0, tot = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (i != 1 && i != n) sum += a[i] / 2, tot += a[i] & 1;
		}
		if (n == 3 && a[2] % 2 == 1)
		{
			puts("-1");
			continue;
		}
		if (tot == n - 2 && !sum) puts("-1");
		else printf("%lld\n", sum + tot);
	}
	return 0;
}