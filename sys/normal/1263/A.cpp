#include <bits/stdc++.h>
using namespace std;
int T, a[5];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &a[1], &a[2], &a[3]);
		sort(a + 1, a + 4);
		if (a[1] + a[2] > a[3])
			printf("%d\n", (a[1] + a[2] + a[3]) / 2);
		else
			printf("%d\n", a[2] + min(a[1], a[3] - a[2]));
	}
	return 0;
}