#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e16;
ll m;

ll solve(ll x)
{
	ll ans = 0;
	for (ll k = 2; ans < INF; k++)
	{
		ll p = k * k * k;
		if (p > x) break;
		ans += x / p;
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld", &m);
	ll l = 0, r = INF;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		if (solve(x) >= m)
			r = x;
		else
			l = x;
	}
	if (solve(r) == m)
		printf("%lld\n", r);
	else
		printf("-1\n");

	return 0;
}