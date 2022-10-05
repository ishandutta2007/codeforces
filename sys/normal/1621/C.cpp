#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;
int T, n, p[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		memset(p, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			if (!p[i])
			{
				int now = 0, f = 0;
				while (true)
				{
					int x;
					printf("? %d\n", i);
					fflush(stdout);
					scanf("%d", &x);
					p[now] = x;
					now = x;
					if (f == x) break;
					if (!f) f = x;
				}
			}
		printf("! ");
		for (int i = 1; i <= n; i++)
			printf("%d%c", p[i], i == n ? '\n' : ' ');
		fflush(stdout);
	}
	return 0;
}