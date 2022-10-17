#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long f(long long n, long long x, bool odd)
{
	if(n == 1)
		return 1;
	if(x % 2 != odd)
		return (x + 1) / 2;
	return f(n - (n - odd + 1) / 2, (x + 1) / 2, n % 2 != odd) + (n - odd + 1) / 2;
}
long long n, x;
int q;
int main()
{
	scanf("%I64d%d", &n, &q);
	for(int i = 1; i <= q; i++)
	{
		scanf("%I64d", &x);
		printf("%I64d\n", f(n, x, 0));
	}
	return 0;
}