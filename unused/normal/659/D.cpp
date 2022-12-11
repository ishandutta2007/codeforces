#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int x[1005], y[1005];

int getdr(int dx, int dy)
{
	if (dx == 0)
	{
		if (dy > 0) return 1;
		else return 3;
	}
	else if (dx < 0) return 0;
	else return 2;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}

	x[n + 1] = x[1];
	y[n + 1] = y[1];

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int adr = getdr(x[i + 1] - x[i], y[i + 1] - y[i]);
		int bdr = getdr(x[i + 2] - x[i + 1], y[i + 2] - y[i + 1]);
		if ((adr + 1) % 4 != bdr)
			ans++;
	}

	printf("%d\n", ans);
}