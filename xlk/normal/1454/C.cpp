#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		n = unique(a, a + n) - a;
		map<int, int> c;
		for (int i = 0; i < n; i++)
		{
			c[a[i]]++;
		}
		c[a[0]]--;
		c[a[n - 1]]--;
		int z = n;
		for (auto i: c)
		{
			z = min(z, i.second + 1);
		}
		printf("%d\n", z);
	}
	return 0;
}