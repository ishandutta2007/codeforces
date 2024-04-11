#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100;
const int MaxM = 100;

int main()
{
	int n, m;
	static int a[MaxN + 1][MaxM + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);

	static bool bookR[MaxN + 1], bookC[MaxM + 1];
	int times = 100;
	while (times--)
	{
		for (int i = 1; i <= n; i++)
		{
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += a[i][j];
			if (sum < 0)
			{
				for (int j = 1; j <= m; j++)
					a[i][j] = -a[i][j];
				bookR[i] = !bookR[i];
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int sum = 0;
			for (int j = 1; j <= n; j++)
				sum += a[j][i];
			if (sum < 0)
			{
				for (int j = 1; j <= n; j++)
					a[j][i] = -a[j][i];
				bookC[i] = !bookC[i];
			}
		}
	}

	cout << count(bookR + 1, bookR + n + 1, true);
	for (int i = 1; i <= n; i++)
		if (bookR[i])
			printf(" %d", i);
	cout << endl;
	cout << count(bookC + 1, bookC + m + 1, true);
	for (int i = 1; i <= m; i++)
		if (bookC[i])
			printf(" %d", i);
	cout << endl;

	return 0;
}