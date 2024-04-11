#include <bits/stdc++.h>
using namespace std;

int T, n;
long long k, x1;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lld", &n, &k);
		long long g = 0;
		for (int i = 1; i <= n; i++)
		{
			long long x;
			scanf("%lld", &x);
			if (i == 1) x1 = x;
			else g = __gcd(g, x - x1);
		}
		if ((k - x1) % g == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}