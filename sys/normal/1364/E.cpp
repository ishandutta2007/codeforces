
#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 2055;
int n, now, pos, a[Maxn];
bool vis[Maxn];
int get_val(int p)
{
	int tmp = (1 << 20) - 1;
	for (int i = 1; i <= 15; i++)
	{
		int x = rand() % n + 1;
		while (x == p) x = rand() % n + 1;
		printf("? %d %d\n", x, p);
		fflush(stdout);
		scanf("%d", &x);
		tmp &= x;
	}
	return tmp;
}
int main()
{
	scanf("%d", &n);
	pos = rand() % n + 1;
	while ((now = get_val(pos)))
	{
		vis[pos] = true;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
			{
				printf("? %d %d\n", i, pos);
				fflush(stdout);
				int x;
				scanf("%d", &x);
				if (x != now) vis[i] = true;
				else
				{
					pos = i;
					break;
				}
			}
	}
	for (int i = 1; i <= n; i++)
		if (i != pos)
		{
			printf("? %d %d\n", i, pos);
			fflush(stdout);
			scanf("%d", &a[i]);
		}
	printf("! ");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	puts("");
	fflush(stdout);
	return 0;
}