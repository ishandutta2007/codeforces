#include "bits/stdc++.h"
using namespace std;

struct mal
{
	char type;
	long long x, y;
};

mal dat[500005];

int main()
{
	int n;
	scanf("%d", &n);
	long long x, y;
	scanf("%lld%lld", &x, &y);

	for (int i = 0; i < n; i++)
	{
		scanf(" %c%lld%lld", &dat[i].type, &dat[i].x, &dat[i].y);
		dat[i].x -= x;
		dat[i].y -= y;
	}

	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			if (dx == 0 && dy == 0) continue;

			int minval = -1;
			long long mindist = 1e18;

			for (int j = 0; j < n; j++)
			{
				if (dx == -1 && dat[j].x >= 0) continue;
				if (dx == 0 && dat[j].x) continue;
				if (dx == 1 && dat[j].x <= 0) continue;
				if (dy == -1 && dat[j].y >= 0) continue;
				if (dy == 0 && dat[j].y) continue;
				if (dy == 1 && dat[j].y <= 0) continue;
				if (dat[j].x * dy != dat[j].y * dx) continue;

				long long md = abs(dat[j].x) + abs(dat[j].y);
				if (md < mindist)
				{
					mindist = md; minval = j;
				}
			}

			if (minval == -1) continue;

			if (dx && dy && dat[minval].type == 'R') continue;
			if ((dx == 0 || dy == 0) && dat[minval].type == 'B') continue;
			printf("YES");
			return 0;
		}
	}

	printf("NO");
}