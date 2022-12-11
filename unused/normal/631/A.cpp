#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	long long ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		ans1 |= tmp;
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		ans2 |= tmp;
	}
	printf("%lld\n", ans1 + ans2);
}