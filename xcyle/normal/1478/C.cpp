#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
#define int long long
using namespace std;
int t, n;
long long a[maxn];
signed main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++)
		{
			scanf("%lld", &a[i]);
		}
		sort(a + 1, a + 2 * n + 1);
		long long now = 0;
		int flag = 0;
		long long last = 2000000000000;
		a[2 * n + 1] = last;
		for (long long i = 2 * n; i >= 1; i -= 2)
		{
			long long t = (a[i] - now) / i;
			if(a[i] == a[i + 1] || a[i] != a[i - 1] || t <= 0 || (a[i] - now) % i != 0 || t >= last)
			{
				flag = 1;
				printf("NO\n");
				break;
			}
			now += 2 * t;
			last = t;
		}
		if(!flag) printf("YES\n");
	}
	return 0;
}