#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100;

int main()
{
	int n;
	static bool mat[MaxN][MaxN];

	int k;
	cin >> k;

	n = 0;
	for (int i = MaxN; i >= 3; i--)
	{
		int t = i * (i - 1) * (i - 2) / 6;
		if (k >= t)
		{
			for (int j1 = 0; j1 < i; j1++)
				for (int j2 = 0; j2 < i; j2++)
					mat[j1][j2] = j1 != j2;
			n = i;
			k -= t;
			break;
		}
	}

	for (int i = MaxN; i >= 2; i--)
	{
		int t = i * (i - 1) / 2;
		while (k >= t)
		{
			for (int j1 = 0; j1 < i; j1++)
				mat[j1][n] = mat[n][j1] = true;
			n++;
			k -= t;
		}
	}

	cout << n << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d", mat[i][j] ? 1 : 0);
		printf("\n");
	}

	return 0;
}