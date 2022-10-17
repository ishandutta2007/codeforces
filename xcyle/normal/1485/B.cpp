#include <iostream>
#include <cstdio>
#define maxn 100005
using namespace std;
int n, q, l, r;
long long k, a[maxn], sum[maxn];
int main()
{
	scanf("%d%d%lld", &n, &q, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + (a[i + 1] - a[i - 1] - 2);
	}
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &l, &r);
		if(l == r)
		{
			printf("%lld\n", k - 1);
			continue;
		}
		printf("%lld\n", a[l + 1] - 2 + (k - a[r - 1] - 1) + sum[r - 1] - sum[l]);
	}
	return 0;
}