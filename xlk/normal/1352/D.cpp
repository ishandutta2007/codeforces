#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1020];
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
		int l = 0;
		int r = n - 1;
		int s = 0;
		int t = 0;
		int x = 0;
		int y = 0;
		int c = 0;
		while (l <= r)
		{
			s = 0;
			c++;
			while (l <= r && s <= t)
			{
				x += a[l];
				s += a[l++];
			}
			if (l > r)
			{
				break;
			}
			t = 0;
			c++;
			while (l <= r && t <= s)
			{
				y += a[r];
				t += a[r--];
			}
		}
		printf("%d %d %d\n", c, x, y);
	}
	return 0;
}