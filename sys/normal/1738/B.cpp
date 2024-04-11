#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, k, a[Maxn], s[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = n - k + 1; i <= n; i++)
			scanf("%d", &s[i]);
		if (k == 1)
		{
			puts("YES");
			goto END;
		}
		for (int i = n - k + 2; i <= n; i++)
		{
			a[i] = s[i] - s[i - 1];
			if (i != n - k + 2 && a[i] < a[i - 1])
			{
				puts("NO");
				goto END;
			}
		}
		puts(a[n - k + 2] * (n - k + 1LL) < s[n - k + 1] ? "No" : "Yes");
		END:;
	}
	return 0;
}