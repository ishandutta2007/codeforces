#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;
int t, n;
long long k, a[maxn];
long long gcd(long long x, long long y)
{
	if(x < y) swap(x, y);
	return y == 0 ? x : gcd(y, x % y); 
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%lld", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
		sort(a + 1, a + n + 1);
		long long tmp = a[2] - a[1];
		for (int i = 3; i <= n; i++)
		{
			tmp = gcd(tmp, a[i] - a[i - 1]);
		}
		if((k - a[1]) % tmp == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}