#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
long long n;

int main()
{
	scanf("%I64d", &n);
	long long a = 0;
	int ans = 0;
	while(a * 10 + 9 <= n)
		a = a * 10 + 9, ans += 9;
	n -= a;
	while(n > 0)
	{
		ans += n % 10;
		n /= 10;
	}
	printf("%d\n", ans);
	return 0;
}