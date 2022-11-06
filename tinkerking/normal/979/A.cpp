#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL N;

int main()
{
	scanf("%lld",&N);
	N++;
	if (N == 1)
	{
		return 0 * puts("0");
	}
	if (N % 2 == 0)
	{
		printf("%lld\n", N / 2);
	}
	else
	{
		printf("%lld\n", N);
	}
}