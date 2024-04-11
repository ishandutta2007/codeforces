#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int q;
int main()
{
	scanf("%d", &q);
	while (q--)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a > b)
		{
			swap(a, b);
		}
		if (a > c)
		{
			swap(a, c);
		}
		if (b > c)
		{
			swap(b, c);
		}
		printf("%lld\n", b + (a + c - b) / 2);
	}
	return 0;
}