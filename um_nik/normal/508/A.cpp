#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 1010;
int n, m, k;
int a[N][N];
bool used[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (used[x][y]) continue;
		used[x][y] = 1;
		for (int j = 0; j < 2; j++)
			for (int s = 0; s < 2; s++)
			{
				a[x + j][y + s]++;
				if (a[x + j][y + s] == 4)
				{
					printf("%d\n", i);
					return 0;
				}
			}
	}
	printf("0\n");

	return 0;
}