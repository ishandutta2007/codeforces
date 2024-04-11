#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000;

int main()
{
	int n;
	static int a[MaxN + 1][MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);

	int res = 0;
	for (int i = 1; i <= n; i++)
		res ^= a[i][i];

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int type;
		scanf("%d", &type);

		if (type == 1)
		{
			int r;
			scanf("%d", &r);
			res ^= 1;
		}
		else if (type == 2)
		{
			int c;
			scanf("%d", &c);
			res ^= 1;
		}
		else
			printf("%d", res);
	}
	printf("\n");

	return 0;
}