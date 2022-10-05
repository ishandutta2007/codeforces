#include <bits/stdc++.h>
using namespace std;

const int Maxn = 35;
int T, n, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int cnt = 0, maxi = 0, tot = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			while (a[i] % 2 == 0) a[i] /= 2, cnt++;
			maxi = max(maxi, a[i]);
			tot += a[i];
		}
		printf("%lld\n", tot + maxi * ((1LL << cnt) - 1));
	}
	return 0;
}