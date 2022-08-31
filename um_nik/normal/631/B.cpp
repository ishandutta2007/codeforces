#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 10100;
int n, m;
int a[N][2], b[N][2];

int main()
{
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++)
	{
		int t, x, c;
		scanf("%d%d%d", &t, &x, &c);
		x--;
		if (t == 1)
		{
			a[x][0] = c;
			a[x][1] = i;
		}
		else
		{
			b[x][0] = c;
			b[x][1] = i;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][1] > b[j][1])
				printf("%d ", a[i][0]);
			else
				printf("%d ", b[j][0]);
		}
		printf("\n");
	}

	return 0;
}