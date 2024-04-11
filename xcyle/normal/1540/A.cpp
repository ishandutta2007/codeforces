#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 100005
using namespace std;
int t, n;
long long a[maxn];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		long long ans = a[n];
		for (int i = 1; i <= n; i++)
		{
			ans += -(long long)(i - 1) * a[i] + (long long)(n - i) * a[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}