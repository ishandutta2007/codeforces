#include <bits/stdc++.h>
using namespace std;
int n, mn = 1e9, mn2 = 1e9;
int a[200020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (mn > a[i])
		{
			mn2 = mn;
			mn = a[i];
		}
		else if (mn2 > a[i])
		{
			mn2 = a[i];
		}
	}
	int z = (mn + 1) / 2 + (mn2 + 1) / 2;
	for (int i = 1; i < n; i++)
	{
		if (a[i] * 2 < a[i - 1])
		{
			z = min(z, (a[i - 1] + 1) / 2);
		}
		else if (a[i - 1] * 2 < a[i])
		{
			z = min(z, (a[i] + 1) / 2);
		}
		else
		{
			z = min(z, (a[i] + a[i - 1] + 2) / 3);
		}
	}
	for (int i = 2; i < n; i++)
	{
		z = min(z, a[i - 2] / 2 + a[i] / 2 + 1);
	}
	printf("%d\n", z);
	return 0;
}