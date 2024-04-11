#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505 * 505;
int n, ct;
pair <int, int> ans[Maxn];
int main()
{
	scanf("%d", &n);
	ans[++ct] = make_pair(0, 1), ans[++ct] = make_pair(1, 1);
	for (int i = 2; i <= n + 1; i++)
	{
		ans[++ct] = make_pair(i - 2, i);
		ans[++ct] = make_pair(i - 1, i);
		ans[++ct] = make_pair(i, i);
	}
	ans[++ct] = make_pair(n, n + 2), ans[++ct] = make_pair(n + 1, n + 2);
	printf("%d\n", ct);
	for (int i = 1; i <= ct; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}