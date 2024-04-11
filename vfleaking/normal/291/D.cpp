#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 10000;

int main()
{
	int n, k;

	cin >> n >> k;

	for (int ti = 1; ti <= k; ti++)
	{
		static int c[MaxN];
		int t = 1 << ti;
		for (int i = 0; i < n; i++)
		{
			if (i % t == 0)
				c[i] = i;
			else if (i % t <= t / 2)
				c[i] = 0;
			else
				c[i] = t / 2;
		}
		for (int i = 0; i < n; i++)
			c[i] = n - c[i];
		reverse(c, c + n);
		for (int i = 0; i < n; i++)
			printf("%d ", c[i]);
		printf("\n");
	}

	return 0;
}