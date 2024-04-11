#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 200000;

int main()
{
	int n;
	static int a[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	static int res[MaxN + 1];
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 1; k <= i; k = i / (i / k) + 1)
			if (a[i + 1] < a[i / k])
				res[k]++, res[i / (i / k) + 1]--;
		if (a[i + 1] < a[0])
			res[i + 1]++;
	}

	for (int i = 1; i <= n - 1; i++)
	{
		res[i] += res[i - 1];
		printf("%d ", res[i]);
	}
	printf("\n");

	return 0;
}