#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;

ll ans1 = 0;
int ans2 = 0;
ll x;

ll getCub(ll x)
{
	if (x == 0) return 0;
	ll y = (ll)pow((double)x, 1. / 3) - 2;
	y = max(y, 0LL);
	while(y * y * y <= x) y++;
	return y - 1;
}

int getCount(ll x)
{
	if (x < 8) return x;
	ll y = getCub(x);
	ll z = x - y * y * y;
	y--;
	return 1 + getCount(max(z, 3 * y * y + 3 * y));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%lld", &x);
	ans2 = getCount(x);
	ans1 = 0;
	int lst = ans2;
	while(x > 0)
	{
		if (x < 8)
		{
			ans1 += x;
			break;
		}
		lst--;
		ll y = getCub(x);
		ll z = x - y * y * y;
		if (lst == getCount(z))
		{
			ans1 += y * y * y;
			x = z;
		}
		else
		{
			y--;
			x = 3 * y * y + 3 * y;
			ans1 += y * y * y;
		}
	}
	printf("%d %lld\n", ans2, ans1);

	return 0;
}