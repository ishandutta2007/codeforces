#include <bits/stdc++.h>
using namespace std;

int T, n, m, maxi;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		maxi = -1;
		scanf("%d%d", &n, &m);
		int x, ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (x <= m) maxi = max(maxi, x);
			else ans = 2;
		}
		if (maxi == -1)
			puts("2");
		else 
			printf("%d\n", min(ans, (int)ceil((double) m / maxi)));
	}
	return 0;
}