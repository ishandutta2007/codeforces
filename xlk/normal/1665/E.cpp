#include <bits/stdc++.h>
using namespace std;
int cases, n, q;
int t[18][100020];
void build(int x, int l, int r, int d)
{
	if (l + 1 == r)
	{
		scanf("%d", &t[d][l]);
		return;
	}
	int m = (l + r) / 2;
	build(x * 2, l, m, d + 1);
	build(x * 2 + 1, m, r, d + 1);
	merge(t[d + 1] + l, t[d + 1] + m, t[d + 1] + m, t[d + 1] + r, t[d] + l);
}
vector<int> query(int x, int l, int r, int d, int L, int R)
{
	if (L <= l && r <= R)
	{
		return vector<int>(t[d] + l, t[d] + min(l + 31, r));
	}
	if (r <= L || R <= l)
	{
		return vector<int>();
	}
	int m = (l + r) / 2;
	vector<int> a = query(x * 2, l, m, d + 1, L, R);
	vector<int> b = query(x * 2 + 1, m, r, d + 1, L, R);
	vector<int> c;
	merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
	if (c.size() > 31)
	{
		c.resize(31);
	}
	return c;
}
int main()
{
	scanf("%d", &cases);
	for (int tt = 0; tt < cases; tt++)
	{
		scanf("%d", &n);
		build(1, 0, n, 0);
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			vector<int> c = query(1, 0, n, 0, l - 1, r);
			int z = 1 << 30;
			for (int i = 0; i < c.size(); i++)
			{
				for (int j = 0; j < i; j++)
				{
					z = min(z, c[i] | c[j]);
				}
			}
			printf("%d\n", z);
		}
	}
	return 0;
}