#include <bits/stdc++.h>
using namespace std;
int t, n, k, x;
int a[200020];
long long s[200020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &k);
		map<int, int> g;
		int b = -1, d = -1, c = 0, l = 0, r = -1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			g[x]++;
		}
		for (auto i : g)
		{
			if (i.second >= k)
			{
				if (i.first == d + 1)
				{
					c++;
				}
				else
				{
					c = 1;
					b = i.first;
				}
				d = i.first;
				if (c > r - l + 1)
				{
					l = b;
					r = b + c - 1;
				}
			}
		}
		if (r == -1)
		{
			puts("-1");
		}
		else
		{
			printf("%d %d\n", l, r);
		}
	}
	return 0;
}