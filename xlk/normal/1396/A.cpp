#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	if (n > 1)
	{
		printf("%d %d\n", 2, n);
		for (int i = 1; i < n; i++)
		{
			printf("%lld%c", a[i] * (n - 1), i == n - 1 ? '\n' : ' ');
		}
		printf("%d %d\n", 1, n);
		printf("%d ", 0);
		for (int i = 1; i < n; i++)
		{
			printf("%lld%c", -a[i] * n, i == n - 1 ? '\n' : ' ');
		}
	}
	else
	{
		printf("%d %d\n%d\n", 1, 1, 0);
		printf("%d %d\n%d\n", 1, 1, 0);
	}
	printf("%d %d\n%lld\n", 1, 1, -a[0]);
	return 0;
}