#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
int T, n;
int a[maxn];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 0 && a[i - 1] == 0)
		{
			printf("-1\n");
			return;
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
		{
			if (i >= 1 && a[i - 1] == 1) ans += 5;
			else ans++;
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		solve();
	}
}