#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		vector<int> c(10), a;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			x %= 10;
			if (c[x]++ < 3)
			{
				a.push_back(x);
			}
		}
		int f = 0;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < j; k++)
				{
					if ((a[i] + a[j] + a[k]) % 10 == 3)
					{
						f = 1;
					}
				}
			}
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}