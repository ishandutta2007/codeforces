#include <bits/stdc++.h>
using namespace std;

int pref[303][303];
int perm[303];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			pref[i][tmp] = n - j + 1;
		}
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		perm[tmp] = n - i + 1;
	}

	for (int i = 1; i <= n; i++)
	{
		int best = 0;
		int ans = 0, ans2 = 0;

		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (perm[best] < perm[j]) best = j;
			if (pref[i][ans] < pref[i][best])
			{
				ans = best;
				ans2 = i;
			}
		}

		printf("%d ", ans);
	}
	printf("\n");
}