#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, a[Maxn];
pair <int, int> vis[5000005];
mt19937 rd(1);
int main()
{
	for (int i = 2; i <= 5000000; i++)
		vis[i] = make_pair(-1, -1);
	srand(time(NULL));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int T = 30000000;
	while (T--)
	{
		int x, y;
		A:x = rd() % n + 1, y = rd() % n + 1;
		if (x == y) goto A;
		if (x > y) swap(x, y);
		int s = a[x] + a[y];
		if (vis[s] != make_pair(-1, -1) && vis[s].first != x && vis[s].second != x && vis[s].first != y && vis[s].second != y)
		{
			printf("YES\n%d %d %d %d\n", vis[s].first, vis[s].second, x, y);
			return 0;;
		}
		else vis[s] = make_pair(x, y);
	}
	puts("NO");
	return 0;
}