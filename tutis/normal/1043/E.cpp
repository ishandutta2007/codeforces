/*input
5 3
-1 3
2 4
1 1
3 5
2 2
1 4
2 3
3 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct XXX
{
	ll x, y, i;
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	XXX a[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].i = i;
	}
	ll ans[n + 1];
	fill_n(ans, n + 1, 0);
	while (m--)
	{
		ll i, j;
		cin >> i >> j;
		ll sc = min(a[i].x + a[j].y, a[i].y + a[j].x);
		ans[i] -= sc;
		ans[j] -= sc;
	}
	for (ll i = 1; i <= n; i++)
	{
		ans[a[i].i] -= a[i].x + a[i].y;
	}
	sort(a + 1, a + n + 1, [](XXX c, XXX d) {return c.x - c.y > d.x - d.y;});
	ll sumx[n + 1];
	ll sumy[n + 1];
	sumx[0] = 0;
	sumy[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		sumx[i] = sumx[i - 1] + a[i].x;
		sumy[i] = sumy[i - 1] + a[i].y;
	}
	for (ll i = 1; i <= n; i++)
	{
		ll k = 0;
		if (a[i].x - a[i].y <= a[1].x - a[1].y)
		{
			ll lo = 1;
			ll hi = n;
			while (lo < hi)
			{
				ll m = (lo + hi + 1) / 2;
				if (a[i].x - a[i].y <= a[m].x - a[m].y)
					lo = m;
				else
					hi = m - 1;
			}
			k = (lo + hi) / 2;
		}
		ans[a[i].i] += a[i].x * k;
		ans[a[i].i] += sumy[k];
		ans[a[i].i] += a[i].y * (n - k);
		ans[a[i].i] += sumx[n] - sumx[k];
	}
	for (ll i = 1; i <= n; i++)
		cout << ans[i] << " ";
}