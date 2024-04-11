#include <bits/stdc++.h>
using namespace std;
int a[400020], n, m, x, z;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		a[x % m]++;
		while (z / m < a[z % m])
		{
			z++;
		}
		printf("%d\n", z);
	}
	return 0;
}