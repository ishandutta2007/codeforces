#include <bits/stdc++.h>
using namespace std;

int T;
long long a, b, c, x, y, z;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		y = b, x = a + (c / b + 1) * b, z = x + c;
		printf("%lld %lld %lld\n", x, y, z);
	}
	return 0;
}