#include <bits/stdc++.h>
using namespace std;

int T, n, cnt[105];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		memset(cnt, 0, sizeof(int[101]));
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (cnt[abs(x)] <= 1 - (x == 0)) ans++;
			cnt[abs(x)]++;
		}
		printf("%d\n", ans);
	}
	return 0;
}