#include <bits/stdc++.h>
using namespace std;
int n, x, z;
int a[2000020];
int s[2000020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a[x] = 1;
	}
	for (int i = 1; i <= 2000000; i++)
	{
		s[i] = a[i] ? i : s[i - 1];
	}
	for (int i = 1; i <= 2000000; i++)
	{
		if (a[i])
		{
			for (int j = 2 * i; j <= 2000000; j += i)
			{
				z = max(z, s[j-1] % i);
			}
		}
	}
	printf("%d\n", z);
	return 0;
}