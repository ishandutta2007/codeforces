#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, k, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n == 1)
		{
			puts(a[1] == k ? "Yes" : "No");
			goto END;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] == k) goto A;
		puts("No");
		goto END;
		A:for (int i = 1; i < n; i++)
			if (a[i] >= k && a[i + 1] >= k)
			{
				puts("Yes");
				goto END;
			}
		for (int i = 1; i < n - 1; i++)
			if (a[i] >= k && a[i + 2] >= k)
			{
				puts("Yes");
				goto END;
			}
		puts("NO");
		END:;
	}
	return 0;
}