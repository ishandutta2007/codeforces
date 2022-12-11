#include "bits/stdc++.h"
using namespace std;

using ll = long long;

ll dp[2][10005];
ll a[10005], b[10005];

int main()
{
	int n; ll c;
	scanf("%d%lld",&n,&c);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = 1; i <= n; i++) scanf("%lld",&b[i]);

	auto *d = dp[0], *e = dp[1];

	for (int i = 1; i <= n; i++)
	{
		e[0] = d[0] + a[i];
		for (int j = 1; j < i; j++)
		{
			e[j] = min(d[j-1]+b[i],d[j]+j*c+a[i]);
		}
		e[i] = d[i-1] + b[i];

		swap(d, e);
	}

	printf("%lld\n",*min_element(d,d+n+1));
}