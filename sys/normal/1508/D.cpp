#include <bits/stdc++.h>
using namespace std;
	 
const int Maxn = 4005;
int n, ct, pos, a[Maxn], x[Maxn], y[Maxn], fa[Maxn], ord[Maxn];
pair <int, int> ans[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
}
int main()
{
	scanf("%d", &n);
	x[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &a[i]), fa[i] = i;
		if (a[i] != i && x[i] < x[pos]) pos = i;
	}
	if (!pos)
	{
		puts("0");
		return 0;
	}
	int tmpx = x[pos], tmpy = y[pos];
	for (int i = 1; i <= n; i++) x[i] -= tmpx, y[i] -= tmpy, ord[i] = i, merge(i, a[i]);
	sort(ord + 1, ord + 1 + n, [](int a, int b){if (a == pos) return true; if (b == pos) return false; return atan2(y[a], x[a]) < atan2(y[b], x[b]);});
	for (int i = 2; i <= n; i++)
	{
		int to = i == n ? 2 : i + 1;
		if (get_fa(ord[i]) != get_fa(ord[to])) ans[++ct] = make_pair(ord[i], ord[to]), merge(ord[i], ord[to]), swap(a[ord[i]], a[ord[to]]);
	}
	while (a[pos] != pos)
		ans[++ct] = make_pair(pos, a[pos]), swap(a[pos], a[a[pos]]);
	printf("%d\n", ct);
	for (int i = 1; i <= ct; i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}