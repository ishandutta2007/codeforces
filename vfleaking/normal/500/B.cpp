#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 300;

int main()
{
	int n;
	static int p[MaxN + 1];
	static char a[MaxN + 1][MaxN + 2];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i][k] == '1' && a[k][j] == '1')
					a[i][j] = '1';

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i][j] == '1' && p[j] < p[i])
				swap(p[i], p[j]);

	for (int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	cout << endl;

	return 0;
}