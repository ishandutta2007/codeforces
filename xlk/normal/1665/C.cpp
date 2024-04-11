#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int c[200020];
bool ok(int M)
{
	int q = M;
	for (int i = 0; i < n; i++)
	{
		if (c[i] > 0)
		{
			q--;
			q -= max(c[i] - (M - i), 0);
		}
	}
	return q >= 0;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
		{
			c[i] = 0;
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			c[x]++;
		}
		c[0]++;
		sort(c, c + n + 1, greater<int>());
		int L = 0, R = n + 1;
		while (L < R - 1)
		{
			int M = (L + R) / 2;
			if (ok(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		printf("%d\n", R);
	}
	return 0;
}