#include <bits/stdc++.h>
using namespace std;
int n, p;
int cal(int x)
{
	if (!x) return 0;
	return cal(x >> 1) + (x & 1);
}
int main()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= 30; i++)
	{
		n -= i * p;
		if (n >= i && cal(n) <= i)
		{
			printf("%d", i);
			return 0;
		}
		n += i * p;
	}
	printf("-1");
	return 0;
}