#include <bits/stdc++.h>
using namespace std;
int t, n, x, s;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d", &n, &s);
		vector<int> a;
		a.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (x)
			{
				a.push_back(i);
			}
		}
		a.push_back(n + 1);
		int z = -1;
		for (int i = 0; i + s + 1 < a.size(); i++)
		{
			z = max(z, a[i + s + 1] - a[i] - 1);
		}
		if (z != -1)
		{
			z = n - z;
		}
		printf("%d\n", z);
	}
	return 0;
}