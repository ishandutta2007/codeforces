#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn];
bool vis[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(vis, 0, sizeof(bool[n]));
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
		{
			if (vis[((a[i] + i) % n + n) % n])
			{
				puts("No");
				goto END;
			}
			vis[((a[i] + i) % n + n) % n] = true;
		}
		puts("Yes");
		END:;
	}
	return 0;
}