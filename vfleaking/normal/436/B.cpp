#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 2000;
const int MaxM = 2000;

int main()
{
	int n, m, nK;
	static char a[MaxN][MaxM + 1];

	cin >> n >> m >> nK;
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	static int res[MaxM];
	for (int x = 0; x < n; x++)
		for (int y = 0; y < m; y++)
		{
			switch (a[x][y])
			{
				case 'L':
					if (y >= x)
						res[y - x]++;
					break;
				case 'R':
					if (y + x < m)
						res[y + x]++;
					break;
				case 'U':
					if (x % 2 == 0)
						res[y]++;
					break;
				case 'D':
					break;
			}
		}
	for (int i = 0; i < m; i++)
		printf("%d ", res[i]);
	printf("\n");

	return 0;
}