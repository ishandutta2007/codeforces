#include <bits/stdc++.h>
using namespace std;
int n, a, b = 1023, x, y, z;
char o;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c%d", &o, &x);
		if (o == '&')
		{
			a &= x;
			b &= x;
		}
		else if (o == '|')
		{
			a |= x;
			b |= x;
		}
		else if (o == '^')
		{
			a ^= x;
			b ^= x;
		}
	}
	x = y = z = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a >> i & 1 && b >> i & 1)
		{
			x |= 1 << i;
			y |= 1 << i;
		}
		else if (~a >> i & 1 && b >> i & 1)
		{
			x |= 1 << i;
		}
		else if (a >> i & 1 && ~b >> i & 1)
		{
			x |= 1 << i;
			z |= 1 << i;
		}
	}
	printf("3\n");
	printf("& %d\n", x);
	printf("| %d\n", y);
	printf("^ %d\n", z);
	return 0;
}