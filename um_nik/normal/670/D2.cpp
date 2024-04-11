#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 200200;
const ll INF = (ll)1e10;
int n;
ll k;
ll a[N], b[N];

bool check(ll x)
{
	ll m = 0;
	for (int i = 0; m <= k && i < n; i++)
		m += max(0LL, x * a[i] - b[i]);
	return m <= k;
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	ll l = 0, r = INF;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		if (check(x))
			l = x;
		else
			r = x;
	}
	printf("%lld\n", l);

	return 0;
}