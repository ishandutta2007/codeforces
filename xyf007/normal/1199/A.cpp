#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, x, y, a[100001];
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		bool f = 1;
		for (int j = i - 1; j >= i - x && j >= 1; j--)
		{
			if (a[j] < a[i])
			{
				f = 0;
				break;
			}
		}
		if (!f)
		{
			continue;
		}
		for (int j = i + 1; j <= i + y && j <= n; j++)
		{
			if (a[j] < a[i])
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			printf("%d", i);
			return 0;
		}
	}
	return 0;
}