#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000;

const int MaxN = 200000;

int main()
{
	int n;
	static int a[MaxN + 1];
	static int fa[MaxN + 1];

	cin >> n;
	for (int v = 1; v <= n; v++)
		scanf("%d %d", &fa[v], &a[v]);

	static s64 f[MaxN + 1][2];
	for (int v = 1; v <= n; v++)
	{
		f[v][0] = 0;
		f[v][1] = -INF;
	}
	for (int v = n; v >= 1; v--)
	{
		f[v][1] = max(f[v][1], f[v][0] + a[v]);

		if (fa[v] != -1)
		{
			s64 f0 = f[fa[v]][0], f1 = f[fa[v]][1];
			f[fa[v]][0] = max(f0 + f[v][0], f1 + f[v][1]);
			f[fa[v]][1] = max(f0 + f[v][1], f1 + f[v][0]);
		}
	}

	cout << max(f[1][0], f[1][1]) << endl;

	return 0;
}