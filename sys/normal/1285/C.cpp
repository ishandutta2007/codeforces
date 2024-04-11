#include <bits/stdc++.h>
using namespace std;

long long x, ans = 0x3f3f3f3f3f3f3f3f;
long long gcd(long long x, long long y)
{
	return x == 0 ? y : gcd(y % x, x);
}
int main()
{
	scanf("%lld", &x);
	int maxi = sqrt(x);
	for (long long i = 1; i <= maxi; i++)
	{
		if (x % i) continue;
		if (gcd(i, x / i) != 1) continue;
		if (max(i, x / i) < ans) ans = max(i, x / i);
	}
	printf("%lld %lld", ans, x / ans);
	return 0;
}