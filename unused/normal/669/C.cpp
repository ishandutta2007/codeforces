#include <stdio.h>

int org[105][105];
int *ptr[105][105];

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ptr[i][j] = &org[i][j];
		}
	}
	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d", &type);
		int r, c, v;
		int *tmp;
		switch (type)
		{
		case 1:
			scanf("%d", &r);
			r--;
			tmp = ptr[r][0];
			for (int i = 1; i < m; i++)
			{
				ptr[r][i - 1] = ptr[r][i];
			}
			ptr[r][m - 1] = tmp;
			break;
		case 2:
			scanf("%d", &c);
			c--;
			tmp = ptr[0][c];
			for (int i = 1; i < n; i++)
			{
				ptr[i - 1][c] = ptr[i][c];
			}
			ptr[n - 1][c] = tmp;
			break;
		case 3:
			scanf("%d%d%d", &r, &c, &v);
			r--, c--;
			*ptr[r][c] = v;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", org[i][j]);
		}
		printf("\n");
	}
}