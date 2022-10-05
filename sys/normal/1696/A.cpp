#include <bits/stdc++.h>
using namespace std;

int T, n, z, a;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ans = 0;
		scanf("%d%d", &n, &z);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a);
			ans = max(ans, a | z);
		}
		printf("%d\n", ans);
	}
	return 0;
}