#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long n, k;

int main()
{
	scanf("%I64d%I64d", &n, &k);
	long long l = max(1ll, k - n), r = min(k - 1, n);
	long long ans = max(0ll, (r - l + 1) / 2);
	printf("%I64d\n", ans);
	return 0;
}