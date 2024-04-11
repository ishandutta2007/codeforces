#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;
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
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		puts("");
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}