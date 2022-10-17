#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, pair<int, int> > a[300020];
int mn[2100020];
int ad[2100020];
void add(int x, int v)
{
	ad[x] += v;
	mn[x] += v;
}
void change(int x, int l, int r, int L, int R, int v)
{
	if (L <= l && r <= R)
	{
		add(x, v);
		return;
	}
	if (R <= l || r <= L)
	{
		return;
	}
	int mid = (l + r) / 2;
	if (ad[x])
	{
		add(x * 2, ad[x]);
		add(x * 2 + 1, ad[x]);
		ad[x] = 0;
	}
	change(x * 2, l, mid, L, R, v);
	change(x * 2 + 1, mid, r, L, R, v);
	mn[x] = min(mn[x * 2], mn[x * 2 + 1]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a[i].second.first, &a[i].second.second, &a[i].first);
	}
	sort(a, a + n);
	int z = 1e9;
	for (int i = 0, j = 0;;)
	{
		if (mn[1] == 0)
		{
			if (i == n)
			{
				break;
			}
			change(1, 1, m, a[i].second.first, a[i].second.second, 1);
			i++;
		}
		else
		{
			change(1, 1, m, a[j].second.first, a[j].second.second, -1);
			j++;
		}
		if (mn[1] > 0)
		{
			z = min(z, a[i - 1].first - a[j].first);
		}
	}
	printf("%d\n", z);
	return 0;
}