#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (c == 0)
	{
		if (a == b)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	int p = b - a;
	if (c < 0)
	{
		p *= -1;
		c *= -1;
	}
	if (p < 0 || p % c != 0)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}