#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int y = 1;
		long long x = n, m = n;
		for (long long i = 2; i * i <= n; i++)
		{
			int c = 0;
			while (n % i == 0)
			{
				n /= i;
				c++;
			}
			if (y < c)
			{
				y = c;
				x = i;
			}
		}
		printf("%d\n", y);
		for (int i = 1; i < y; i++)
		{
			printf("%lld ", x);
			m /= x;
		}
		printf("%lld\n", m);
	}
	return 0;
}