#include <bits/stdc++.h>
using namespace std;
int t;
long long k, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%lld%lld", &k, &x);
		if (k * (k + 1) / 2 >= x)
		{
			long long L = 0, R = k;
			while (L < R - 1)
			{
				long long M = (L + R) / 2;
				if (M * (M + 1) / 2 < x)
				{
					L = M;
				}
				else
				{
					R = M;
				}
			}
			cout << R << endl;
		}
		else
		{
			x -= k * (k + 1) / 2;
			long long L = 0, R = k - 1;
			while (L < R - 1)
			{
				long long M = (L + R) / 2;
				if ((k - 1 + k - M) * M / 2 < x)
				{
					L = M;
				}
				else
				{
					R = M;
				}
			}
			cout << k + R << endl;
		}
	}
	return 0;
}