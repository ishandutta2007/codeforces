#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

const int N = (int)5010;
int n, k;
int a[N];
set<int> b;

void read()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		b.insert(a[i]);
	}
	return;
}

void solve()
{
	int y;
	scanf("%d", &y);
	int ans = k + 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= k; j++)
		{
			int x = y - a[i] * j;
			if (x == 0)
			{
				ans = min(ans, j);
				break;
			}
			if (x < 0) break;
			for (int h = 1; j + h <= k; h++)
			{
				if (x % h != 0) continue;
				int z = x / h;
				if (b.count(z) != 0)
					ans = min(ans, j + h);
			}
		}
	if (ans == k + 1)
		printf("-1\n");
	else
		printf("%d\n", ans);
}

int main()
{
	read();
	int q;
	scanf("%d", &q);
	while(q--)
		solve();

	return 0;
}