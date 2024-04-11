#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, a, b;
int s[200][200];

int main()
{
	scanf("%d%d%d", &n, &a, &b);

	if (n > a * b)
	{
		printf("-1\n");
		return 0;
	}
	int x = 1;
	for (int i = 0; i < a; i++)
	{
		if (i % 2 == 1 && b % 2 == 0)
		{
			for (int j = b - 1; j >= 0; j--)
			{
				if (x <= n)
					s[i][j] = x++;
				else
					s[i][j] = 0;
			}
		}
		else
		{
			for (int j = 0; j < b; j++)
			{
				if (x <= n)
					s[i][j] = x++;
				else
					s[i][j] = 0;
			}
		}

		for (int j = 0; j < b; j++)
			printf("%d ", s[i][j]);
		printf("\n");
	}

	return 0;
}