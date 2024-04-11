#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

ll C, a, b, x, y;
const ll B = 1000LL;
ll ans = 0;

int main()
{
	cin >> C >> x >> y >> a >> b;

	if (a < b)
	{
		swap(a, b);
		swap(x, y);
	}

	if (a > B)
	{
		for (ll i = 0; i * a <= C; i++)
		{
			ll w = C - i * a;
			ll tmp = i * x + (w / b) * y;
			ans = max(ans, tmp);
		}
		cout << ans << endl;
		return 0;
	}

	ll ans2 = 0;
	ll mult = a * b;
	ll W = max(b * x, a * y);
	ll p = C % mult + 3 * mult;
	if (p < C)
	{
		ans2 = ((C - p) / mult) * W;
		C = p;
	}
	for (ll i = 0; i * a <= C; i++)
	{
		ll w = C - i * a;
		ll tmp = i * x + (w / b) * y;
		ans = max(ans, tmp);
	}
	cout << ans + ans2 << endl;

	return 0;
}