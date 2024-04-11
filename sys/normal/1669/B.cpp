#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i < n - 1; i++)
			if (a[i] == a[i + 2])
			{
				printf("%d\n", a[i]);
				goto END;
			}
		puts("-1");
		END:;
	}
	return 0;
}