#include <bits/stdc++.h>
using namespace std;
int t;
long long n, l, r, a, b, c, m;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld", &n);
		l = 0;
		r = 100000;
		while (l < r - 1)
		{
			m = (l + r) / 2;
			a = m / 3;
			b = (m + 1) / 3;
			c = (m + 2) / 3;
			if (2 * (a * b + b * c + c * a) >= n)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}
		printf("%lld\n", r);
	}
	return 0;
}