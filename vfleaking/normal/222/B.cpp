#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 1000;
const int MaxM = 1000;

int main()
{
	int n, m, q;
	static int mat[MaxN + 1][MaxM + 1];

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &mat[i][j]);

	static int origR[MaxN + 1], origC[MaxM + 1];
	for (int i = 1; i <= n; i++)
		origR[i] = i;
	for (int j = 1; j <= m; j++)
		origC[j] = j;

	while (q--)
	{
		char c;
		int x, y;
		while (c = getchar(), c != 'c' && c != 'r' && c != 'g');
		scanf("%d %d", &x, &y);

		switch (c)
		{
			case 'c':
				swap(origC[x], origC[y]);
				break;
			case 'r':
				swap(origR[x], origR[y]);
				break;
			case 'g':
				printf("%d\n", mat[origR[x]][origC[y]]);
		}
	}

	return 0;
}