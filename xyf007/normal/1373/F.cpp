#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[1000001], b[1000001];
int check(int x)
{
	int last = b[1] - x;
	for (int i = 2; i <= n; i++)
	{
		if (last + b[i] < a[i])
		{
			return 0;
		}
		if (last >= a[i])
		{
			last = b[i];
		}
		else
		{
			last = b[i] + last - a[i];
		}
	}
	return last + x >= a[1] ? 1 : 2;
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
		}
		int l = 0, r = b[1];
		bool f = 0;
		while (l <= r)
		{
			int mid = (l + r) >> 1, x = check(mid);
			if (x == 1)
			{
				f = 1;
				printf("YES\n");
				break;
			}
			else
			{
				if (!x)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
		}
		if (!f)
		{
			printf("NO\n");
		}
	}
	return 0;
}