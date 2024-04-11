#include <bits/stdc++.h>
using namespace std;

int T;
long long n;
long long solve1(long long x)
{
	long long ans = 0;
	if (!x) return 1;
	x--;
	for (int i = 2; ; i += 2)
	{
		if ((1LL << i) > x)
		{
			ans += (1LL << i);
			break;
		}
		x -= (1LL << i);
	}
	static long long tmp[] = {0, 1, 2, 3};
	for (int i = 0; i <= 60; i += 2)
		ans += tmp[(x >> i) & 3] << i;
	return ans;
}
long long solve2(long long x)
{
	long long ans = 0;
	if (!x) return 2;
	x--;
	for (int i = 2; ; i += 2)
	{
		if ((1LL << i) > x)
		{
			ans += (1LL << i) * 2;
			break;
		}
		x -= (1LL << i);
	}
	static long long tmp[] = {0, 2, 3, 1};
	for (int i = 0; i <= 60; i += 2)
		ans += tmp[(x >> i) & 3] << i;
	return ans;
}
long long solve3(long long x)
{
	long long ans = 0;
	if (!x) return 3;
	x--;
	for (int i = 2; ; i += 2)
	{
		if ((1LL << i) > x)
		{
			ans += (1LL << i) * 3;
			break;
		}
		x -= (1LL << i);
	}
	static long long tmp[] = {0, 3, 1, 2};
	for (int i = 0; i <= 60; i += 2)
		ans += tmp[(x >> i) & 3] << i;
	return ans;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		if (n % 3 == 1) printf("%lld\n", solve1((n - 1) / 3));
		else if (n % 3 == 2) printf("%lld\n", solve2((n - 1) / 3));
		else printf("%lld\n", solve3((n - 1) / 3));
	}
	return 0;
}