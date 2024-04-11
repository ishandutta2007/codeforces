#include <bits/stdc++.h>
using namespace std;

int T, n, a, b;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &a, &b);
		long long now = 1;
		if (a == 1)
		{
			puts((n - 1) % b ? "No" : "Yes");
			continue;
		}
		while (now <= n)
		{
			if ((n - now) % b == 0)
			{
				puts("Yes");
				goto END;
			}
			now *= a;
		}
		puts("No");
		END:;
	}
	return 0;
}