#include <bits/stdc++.h>
using namespace std;

int T, n, k, cnt, a[105];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		a[0] = -0x3f3f3f3f;
		cnt = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			if (a[i] != a[i - 1]) cnt++;
		if (cnt <= k)
		{
			puts("1");
			continue;
		}
		if (cnt && k == 1)
		{
			puts("-1");
			continue;
		}
		cnt -= k;
		printf("%d\n", 1 + (int)ceil(cnt / (k - 1.0)));
	}
	return 0;
}