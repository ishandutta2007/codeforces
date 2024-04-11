#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1)
			x = i;
		if (a == n)
			y = i;
	}
	int ans = max(max(x, y), max(n - 1 - x, n - 1 - y));
	printf("%d\n", ans);

	return 0;
}