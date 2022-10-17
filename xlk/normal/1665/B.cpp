#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		map<int, int> g;
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			c = max(c, ++g[x]);
		}
		int z = n - c;
		while (c < n)
		{
			z++;
			c *= 2;
		}
		printf("%d\n", z);
	}
	return 0;
}