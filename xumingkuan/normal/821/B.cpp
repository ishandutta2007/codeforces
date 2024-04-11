#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int m, b;
long long ans = 0;
int main()
{
	scanf("%d%d", &m, &b);
	for(int i = 0; i <= b; i++)
		ans = max(ans, ((long long)i * (i + 1) / 2) * ((long long)m * (b - i) + 1) + ((long long)m * (b - i) * ((long long)m * (b - i) + 1) / 2) * (i + 1));
	printf("%I64d\n", ans);
	return 0;
}