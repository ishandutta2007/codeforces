#include <bits/stdc++.h>
using namespace std;
int T, n, ct, ans[1000005];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d", &n);
		int End = 0;
		for (int Start = 1; End < n; Start = End + 1)
		{
			End = n / (n / Start);
			ans[++ct] = n / End;
		}
		reverse(ans + 1, ans + 1 + ct);
		printf("%d\n", ct + 1);
		for (int i = 0; i <= ct; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}