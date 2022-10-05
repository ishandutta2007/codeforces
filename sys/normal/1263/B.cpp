#include <bits/stdc++.h>
using namespace std;
int T, n, a[15], res[15], ans;
map <int, int> Ma;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		Ma.clear();
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), res[i] = a[i], Ma[a[i]]++;
		for (int i = 1; i <= n; i++)
		{
			Ma[a[i]]--;
			while (Ma[a[i]]) (a[i] += 1000) %= 10000;
			Ma[a[i]]++;
		}
		for (int i = 1; i <= n; i++)
			if (a[i] != res[i]) ans++;
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
		{
			if (!(a[i] / 1000)) printf("0");
			if (!(a[i] / 100)) printf("0");
			if (!(a[i] / 10)) printf("0");
			if (!a[i]) printf("0");
			if (a[i]) printf("%d\n", a[i]);
			else printf("\n");
		}
	}
	return 0;
}