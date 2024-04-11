#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] < 0)
			{
				a[i] = -a[i];
				c++;
			}
		}
		for (int i = 0; i < c; i++)
		{
			a[i] = -a[i];
		}
		puts(is_sorted(a, a + n) ? "YES" : "NO");
	}
	return 0;
}