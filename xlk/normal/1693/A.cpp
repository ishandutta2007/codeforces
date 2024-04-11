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
		int f = 1, v = 0;
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			s += a[i];
			if (s < 0)
			{
				f = 0;
			}
			if (s == 0)
			{
				v = 1;
			}
			if (v == 1 && s != 0)
			{
				f = 0;
			}
		}
		if (s != 0)
		{
			f = 0;
		}
		puts(f ? "Yes" : "No");
	}
	return 0;
}