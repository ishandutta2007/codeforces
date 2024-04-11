#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, a[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int pos1 = 0, pos2 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i < n; i++)
			if (a[i] == a[i + 1] && !pos1) pos1 = i;
		for (int i = n; i > 1; i--)
			if (a[i] == a[i - 1] && !pos2) pos2 = i;
		if (!pos1 || pos1 + 1 == pos2) puts("0");
		else printf("%d\n", max(1, pos2 - pos1 - 2));
	}
	return 0;
}