#include <bits/stdc++.h>
using namespace std;

int d1[105], d2[105];

int main()
{
	int n, l;
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &d2[i]);
	}

	for (int i = 1, d = 0; i < n; i++)
	{
		if (d1[i] < d1[i - 1])
		{
			if (++d == 2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}

	for (int i = 1, d = 0; i < n; i++)
	{
		if (d2[i] < d2[i - 1])
		{
			if (++d == 2)
			{
				printf("NO\n");
				return 0;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		int diff = (d1[i] + l - d2[0]) % l;
		int j;
		for (j = 0; j < n; j++)
		{
			if ((d1[(i + j) % n] + l - d2[j]) % l != diff) break;
		}
		if (j == n)
		{
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
}