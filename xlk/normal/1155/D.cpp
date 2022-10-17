#include <bits/stdc++.h>
using namespace std;
int n, x, y;
long long a, b, c, d;
int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &y);
		a = max(0LL, a + y);
		b = max(a, b + (long long)y * x);
		c = max(b, c + y);
		d = max(c, d);
	}
	printf("%lld\n", d);
	return 0;
}