#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 200000;
const int MaxLogN = 20;

int main()
{
	int n;
	static int a[MaxN + 1];
	static int fa[MaxN + 1];
	static s64 val[MaxN + 1];

	cin >> n;
	for (int i = 2; i <= n; i++)
		scanf("%d", &a[i]);

	val[1] = 0, fa[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int t = i + a[i];
		val[i] = a[i];
		if (t <= 0 || t > n)
		{
			fa[i] = 0;
			continue;
		}
		val[i] += a[t];
		t -= a[t];
		if (t <= 0 || t > n)
		{
			fa[i] = 0;
			continue;
		}
		fa[i] = t;
	}

	static int q[MaxN];
	static int deg[MaxN + 1];
	int top, bot;

	for (int v = 1; v <= n; v++)
		if (fa[v] != 0)
			deg[fa[v]]++;

	top = bot = 0;
	for (int v = 1; v <= n; v++)
		if (deg[v] == 0)
			q[bot++] = v;
	while (top != bot)
	{
		int v = q[top++];
		if (--deg[fa[v]] == 0)
			q[bot++] = fa[v];
	}

	for (int v = 1; v <= n; v++)
		if (deg[v] != 0)
			val[v] = -1, fa[v] = 0;

	for (int i = bot - 1; i >= 0; i--)
	{
		int v = q[i];
		if (fa[v] == 0)
			fa[v] = v;
		else if (val[fa[v]] == -1)
			val[v] = -1, fa[v] = 0;
		else
			val[v] += val[fa[v]], fa[v] = fa[fa[v]];
	}

	for (int i = 1; i < n; i++)
	{
		a[1] = i;
		s64 res;
		int t = 1 + a[1];
		res = a[1];
		if (0 < t && t <= n)
		{
			res += a[t];
			t -= a[t];
			if (0 < t && t <= n)
			{
				fa[1] = t;
				if (fa[t] == 1 || val[t] == -1)
					res = -1;
				else
					res += val[t];
			}
		}
		cout << res << endl;
	}

	return 0;
}