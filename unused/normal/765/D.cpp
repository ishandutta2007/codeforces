#include <bits/stdc++.h>
using namespace std;

int f[100005];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &f[i]);
	}

	vector<int> fixed;

	for (int i = 1; i <= n; i++)
	{
		int x = f[i];
		if (f[x] != x)
		{
			printf("-1\n");
			return 0;
		}

		if (x == i) fixed.push_back(i);
	}

	printf("%d\n", (int)fixed.size());

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", (int)(lower_bound(fixed.begin(), fixed.end(), f[i]) - fixed.begin()) + 1);
	}

	printf("\n");
	for (int t : fixed) printf("%d ", t);
	printf("\n");
}