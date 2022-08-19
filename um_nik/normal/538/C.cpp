#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int m, n;
int a[N], b[N];
int ans = 0;
bool ok = true;

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i], &b[i]);
	ans = max(ans, b[0] + a[0] - 1);
	ans = max(ans, b[n - 1] + (m - a[n - 1]));
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] < abs(b[i + 1] - b[i]))
			ok = false;
		else
		{
			int d = a[i + 1] - a[i];
			int x = max(b[i + 1], b[i]);
			d -= abs(b[i + 1] - b[i]);
			ans = max(ans, x + d / 2);
		}
	}
	if (!ok)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", ans);

	return 0;
}