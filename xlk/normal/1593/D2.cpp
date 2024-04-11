#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[50];
int v[2000020];
int c[2000020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] += 1000000;
		}
		memset(v, 0, sizeof v);
		for (int d = 2000001; d > 0; d--)
		{
			int w = 0;
			for (int i = 0; i < n; i++)
			{
				if (v[a[i] % d] != d)
				{
					v[a[i] % d] = d;
					c[a[i] % d] = 0;
				}
				w = max(w, ++c[a[i] % d]);
			}
			if (w * 2 >= n)
			{
				if (d == 2000001)
				{
					printf("-1\n");
				}
				else
				{
					printf("%d\n", d);
				}
				break;
			}
		}
	}
	return 0;
}