#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, d, res, tot, fa[Maxn], siz[Maxn];
vector <int> Ve;
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
bool merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		fa[a] = b;
		siz[b] += siz[a];
		return true;
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= d; i++)
	{
		int x, y;
		tot = 0;
		scanf("%d%d", &x, &y);
		res += !merge(x, y);
		for (int j = 1; j <= n; j++)
			if (get_fa(j) == j) Ve.push_back(siz[j]);
		sort(Ve.begin(), Ve.end());
		for (int j = (int) Ve.size() - 1; j >= max(0, (int) Ve.size() - res - 1); j--)
			tot += Ve[j];
		printf("%d\n", tot - 1);
		Ve.clear();
	}
	return 0;
}