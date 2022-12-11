#include "bits/stdc++.h"

bool isprime(long long n)
{
	if (n == 1) return false;
	for (int j = 2; j * j <= n; j++)
	{
		if (n % j == 0) return false;
	}
	return true;
}

int main()
{
	long long n;
	scanf("%lld", &n);

	if (isprime(n)) printf("1");
	else
	{
		if (n % 2 == 0) printf("2");
		else
		{
			if (isprime(n - 2)) printf("2");
			else printf("3");
		}
	}
}