#include <bits/stdc++.h>
using namespace std;

int T, n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			ans += i * (n - i + 1);
			if (!x) ans += i * (n - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}