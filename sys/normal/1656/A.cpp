#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, a[Maxn], ord[Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), ord[i] = i;
		sort(ord + 1, ord + 1 + n, [](int x, int y){return a[x] < a[y];});
		printf("%d %d\n", ord[1], ord[n]);
	}
	return 0;
}