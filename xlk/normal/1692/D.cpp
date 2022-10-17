#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int h, m, x;
		scanf("%d:%d %d", &h, &m, &x);
		int s = h * 60 + m, z = 0;
		for (int i = 0; i < 1440 / __gcd(1440, x); i++)
		{
			int t = (s + x * i) % 1440;
			if (t / 60 / 10 == t % 60 % 10 && t / 60 % 10 == t % 60 / 10)
			{
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}