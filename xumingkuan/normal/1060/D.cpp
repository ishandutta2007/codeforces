#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, l[101010], r[101010];
long long ans = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	for(int i = 1; i <= n; i++)
		ans += max(l[i], r[i]) + 1;
	printf("%I64d\n", ans);
	return 0;
}