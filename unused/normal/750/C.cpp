#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	long long lo = -1e18, hi = 1e18;

	long long diff = 0;

	bool one = false, two = false;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);

		if (b == 1)
		{
			one = true;
			lo = max(lo, 1900 - diff);
		}
		else
		{
			two = true;
			hi = min(hi, 1899 - diff);
		}

		diff += a;
	}

	if (two == false)
	{
		printf("Infinity");
	}
	else if (lo > hi)
	{
		printf("Impossible");
	}
	else
	{
		printf("%lld", hi + diff);
	}
}