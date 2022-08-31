#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = (int)2e9;
const int N = 222;
int n;
int a[N][2];
int b[N][2];

bool can(int p, int l, int r)
{
	for (int i = 0; i < p; i++)
	{
		if (max(l, b[i][0]) < min(r, b[i][1]))
			return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i][0], &a[i][1]);
	for (int it = 0; it < n; it++)
	{
		if (can(it, a[it][0], a[it][0] + a[it][1]))
		{
			b[it][0] = a[it][0];
			b[it][1] = a[it][0] + a[it][1];
			continue;
		}
		int x = 1;
		while(true)
		{
			if (can(it, x, x + a[it][1]))
			{
				b[it][0] = x;
				b[it][1] = x + a[it][1];
				break;
			}
			int y = INF;
			for (int i = 0; i < it; i++)
			{
				if (b[i][1] <= x) continue;
				y = min(y, b[i][1]);
			}
			x = y;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", b[i][0], b[i][1] - 1);

	return 0;
}