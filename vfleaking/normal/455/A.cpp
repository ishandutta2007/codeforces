#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int MaxA = 100000;

int main()
{
	int n;
	static int a[MaxA + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int v;
		scanf("%d", &v);
		a[v]++;
	}

	static s64 f[MaxA + 1], g[MaxA + 1];
	f[0] = g[0] = 0;
	for (int i = 1; i <= MaxA; i++)
	{
		f[i] = (s64)i * a[i] + g[i - 1];
		g[i] = max(g[i - 1], f[i - 1]);
	}

	cout << max(f[MaxA], g[MaxA]) << endl;

	return 0;
}