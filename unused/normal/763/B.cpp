#include <bits/stdc++.h>
using namespace std;

int n;
struct rect
{
	int x1, y1, x2, y2;
} dat[500005];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &dat[i].x1, &dat[i].y1, &dat[i].x2, &dat[i].y2);
	}

	printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", (dat[i].x1 & 1) * 2 + (dat[i].y1 & 1) + 1);
	}
}