#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll a[2][1 << 7];

int getMask(int x, int k)
{
	int mask = 0;
	while(k--)
	{
		int y = x % 7;
		x /= 7;
		if ((mask >> y) & 1) return -1;
		mask |= 1 << y;
	}
	return mask;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int it = 0; it < 2; it++)
	{
		ll x;
		scanf("%lld", &x);
		ll y = x - 1;
		int k = 0;
		while(y > 0)
		{
			y /= 7;
			k++;
		}
		if (k == 0) k = 1;
		if (k > 6)
		{
			printf("0\n");
			return 0;
		}
		for (int i = 0; i < x; i++)
		{
			int mask = getMask(i, k);
			if (mask == -1) continue;
			a[it][mask]++;
		}
	}
	ll ans = 0;
	for (int m1 = 0; m1 < (1 << 7); m1++)
		for (int m2 = 0; m2 < (1 << 7); m2++)
			if ((m1 & m2) == 0)
				ans += a[0][m1] * a[1][m2];
	printf("%lld\n", ans);

	return 0;
}