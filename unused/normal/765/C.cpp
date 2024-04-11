#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k, a, b;
	scanf("%d%d%d", &k, &a, &b);
	int a1 = a / k, b1 = b / k;

	if (a1 == 0 && b1 == 0)
	{
		printf("-1\n");
		return 0;
	}

	if (a1 == 0 && b % k)
	{
		printf("-1\n");
		return 0;
	}

	if (b1 == 0 && a % k)
	{
		printf("-1\n");
		return 0;
	}

	printf("%d\n", a1 + b1);
}