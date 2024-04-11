#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll euclid(ll x, ll y, ll &k, ll &l)
{
	if (y == 0)
	{
		k = 1;
		l = 0;
		return x;
	}
	ll g = euclid(y, x % y, l, k);
	l -= k * (x / y);
	return g;
}

const ll INF = (ll)1e18;

ll n, m;

ll solve(ll x, ll y)
{
	ll g = 0, a = 0, b = 0;
	g = euclid(2 * n, 2 * m, a, b);
	b *= -1;
	if (x % g != y % g) return INF;
	a *= (y - x) / g;
	b *= (y - x) / g;
	ll nn = (2 * n) / g, mm = (2 * m) / g;
	if (x + a * n * 2 != y + b * m * 2) throw;
	if (a < 0)
	{
		ll k = abs(a) / mm;
		a += k * mm;
		b += k * nn;
	}
	while (a < 0)
	{
		a += mm;
		b += nn;
	}
	ll k = min(a / mm, b / nn);
	a -= mm * k;
	b -= nn * k;
	if (x + a * n * 2 != y + b * m * 2) throw;
	return x + a * n * 2;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%lld%lld%d", &n, &m, &q);
	while(q--)
	{
		ll x, y;
		scanf("%lld%lld", &x, &y);
		ll ans = INF;
		ans = min(ans, solve(x, y));
		ans = min(ans, solve(2 * n - x, y));
		ans = min(ans, solve(x, 2 * m - y));
		ans = min(ans, solve(2 * n - x, 2 * m - y));
		if (ans == INF)
			printf("-1\n");
		else
			printf("%lld\n", ans);
	}

	return 0;
}