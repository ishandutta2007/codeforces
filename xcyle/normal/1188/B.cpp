#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 300005
using namespace std;
int n;
long long ans, mo, k, a[maxn];
int main()
{
	scanf("%d%d%d", &n, &mo, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] = (a[i] * a[i] % mo * a[i] % mo * a[i] % mo - k * a[i] % mo + mo) % mo;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		long long cnt = 1;
		while(a[i] == a[i + 1] && i <= n)
		{
			i++;
			cnt++;
		}
		ans = (ans + cnt * (cnt - 1) / 2) % mo;
	}
	printf("%lld", ans);
	return 0;
}