#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000;

int main()
{
	int n;
	cin >> n;

	if (n == 4)
	{
		printf("-1\n");
		return 0;
	}

	static int mat[MaxN + 1][MaxN + 1];

	int st;
	if (n % 2 == 1)
		st = 2;
	else
	{
		mat[1][2] = 1;
		mat[1][3] = 1;
		mat[2][3] = 1;
		mat[2][4] = 1;
		mat[2][5] = 1;
		mat[3][5] = 1;
		mat[3][6] = 1;
		mat[4][1] = 1;
		mat[4][3] = 1;
		mat[4][6] = 1;
		mat[5][1] = 1;
		mat[5][4] = 1;
		mat[5][6] = 1;
		mat[6][1] = 1;
		mat[6][2] = 1;
		
		st = 7;
	}

	for (int i = st; i <= n; i += 2)
	{
		mat[i][i + 1] = 1;
		mat[1][i] = 1;
		mat[i + 1][1] = 1;
		for (int j = 2; j < i; j++)
		{
			if (mat[1][j])
			{
				mat[i][j] = 1;
				mat[j][i + 1] = 1;
			}
			else
			{
				mat[i + 1][j] = 1;
				mat[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", mat[i][j], j < n ? ' ' : '\n');

	return 0;
}