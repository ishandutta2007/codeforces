#include <bits/stdc++.h>
using namespace std;

int T, n, cnt[35];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			for (int j = 0; j <= 30; j++)
				if (x & (1 << j)) cnt[j]++;
		}
		for (int i = 30; i >= 0; i--)
			if (cnt[i] & 1)
			{
				if ((((cnt[i] + 1) >> 1) & 1) || ((n & 1) == 0))
					puts("WIN");
				else
					puts("LOSE");
				goto END;
			}
		puts("DRAW");
		END:;
	}
	return 0;
}