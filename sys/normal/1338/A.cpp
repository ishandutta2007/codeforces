#include <bits/stdc++.h>
using namespace std;

int T, n, maxi, Range;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		maxi = -0x3f3f3f3f;
		Range = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			Range = max(Range, maxi - x);
			maxi = max(maxi, x);
		}
		printf("%d\n", (int) ceil(log2(Range + 1)));
	}
	return 0;
}