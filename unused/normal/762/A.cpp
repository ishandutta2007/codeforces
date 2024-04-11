#include <bits/stdc++.h>
using namespace std;

set<long long> vt;

int main()
{
	long long n; int k;
	scanf("%lld%d", &n, &k);
	for (int i = 1; i * 1ll * i <= n; i++)
	{
		if (n % i == 0)
		{
			vt.insert(n / i);
			vt.insert(i);
		}
	}

	for (auto &&z : vt)
	{
		if (--k == 0)
		{
			printf("%lld", z);
			return 0;
		}
	}
	printf("-1");
}