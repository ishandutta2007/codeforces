#include <bits/stdc++.h>
using namespace std;
int t;
int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int b = 0, g;
		for (int i = 0; i < 30; i++)
		{
			printf("? %d %d\n", (1 << i) - b, (3 << i) - b);
			fflush(stdout);
			scanf("%d", &g);
			// g = gcd(ans + (1 << i) - b, ans + (3 << i) - b);
			if (g != (1 << i))
			{
				b |= 1 << i;
			}
		}
		printf("! %d\n", b);
		fflush(stdout);
	}
	return 0;
}