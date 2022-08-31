#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int N = 1010;
int n;
ll a[N], b[N];

int main()
{
	scanf("%d", &n);
	ll ans = 0;
	ll x = 0;
	for (int i = 0; i < n; i++)
	{
		ll y;
		scanf("%lld", &y);
		x |= y;
	}
	ans += x;
	x = 0;
	for (int i = 0; i < n; i++)
	{
		ll y;
		scanf("%lld", &y);
		x |= y;
	}
	ans += x;
	printf("%lld\n", ans);

	return 0;
}