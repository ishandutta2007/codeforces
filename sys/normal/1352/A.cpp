#include <bits/stdc++.h>
using namespace std;

int T, n, ans[40];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int ct = 0, now = 1;
		scanf("%d", &n);
		while (n)
		{
			if (n % 10) ans[++ct] = n % 10 * now;
			n /= 10, now *= 10;
		}
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}