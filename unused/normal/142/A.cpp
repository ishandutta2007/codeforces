#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	long long a = 1e18, b = -1;

	for (int i = 1; i * i <= n; i++)
	{
		if (n % i) continue;
		int nn = n / i;
		for (int j = 1; j * j <= nn; j++)
		{
			if (nn % j) continue;
			int k = nn / j;

			long long z = (i + 1ll) * (j + 2ll) * (k + 2ll);
			a = min(a, z - n); b = max(b, z - n);
			z = (i + 2ll) * (j + 2ll) * (k + 1ll);
			a = min(a, z - n); b = max(b, z - n);
			z = (i + 2ll) * (j + 1ll) * (k + 2ll);
			a = min(a, z - n); b = max(b, z - n);
		}
	}

	printf("%lld %lld\n", a, b);
}