#include <bits/stdc++.h>
using namespace std;

int T;
int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		int g = gcd(a, b);
		a /= g, b /= g;
		if (a > b) swap(a, b);
		if ((k - 1) * (long long) a + 1 < b) puts("REBEL");
		else puts("OBEY");
	}
	return 0;
}