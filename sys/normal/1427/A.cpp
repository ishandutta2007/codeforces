#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55;
int T, n, a[Maxn], sum;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		sum = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i];
		sort(a + 1, a + 1 + n);
		if (sum == 0) puts("NO");
		else
		{
			puts("YES");
			if (sum < 0)
				for (int i = 1; i <= n; i++)
					printf("%d ", a[i]);
			else
				for (int i = n; i >= 1; i--)
					printf("%d ", a[i]);
			puts("");
		}
	}
	return 0;
}