#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn], b[Maxn], cnt[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int pos = 0;
		scanf("%d", &n);
		a[0] = -1;
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), cnt[i] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++)
		{
			while (a[pos] != b[i] || !cnt[a[pos]])
			{
				pos++;
				if (pos == n + 1)
				{
					puts("NO");
					goto END;
				}
				cnt[a[pos]]++;
			}
			cnt[a[pos]]--;
		}
		puts("YES");
		END:;
	}
	return 0;
}