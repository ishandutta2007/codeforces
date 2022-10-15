/*input
-3 1 6
2
2 4
6 7
5
3 1
1 3
6 1
6 4
7 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll sy, a, b;
	cin >> sy >> a >> b;
	ll z = -sy;
	ll n;
	cin >> n;
	ll l[n + 1];
	ll r[n + 1];
	l[0] = r[0] = -1e18;
	ll suma[n + 1];
	suma[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		suma[i] = r[i] - l[i] + suma[i - 1];
	}
	auto SUMA = [&](pair<ll, ll>R)->ld
	{
		int lo = 0;
		int hi = n;
		while (lo < hi)
		{
			int m = (lo + hi + 1) / 2;
			if (r[m]*R.second <= R.first)
			{
				lo = m;
			}
			else
				hi = m - 1;
		}
		ld ans = suma[lo];
		int k = lo + 1;
		if (k <= n)
		{
			if (r[k]*R.second >= R.first && l[k]*R.second <= R.first)
				ans += ld(R.first) / ld(R.second) - ld(l[k]);
		}
		return ans;
	};
	ll q;
	cin >> q;
	while (q--)
	{
		ll x, y;
		cin >> x >> y;
		pair<ll, ll> L = {(a * y + x * z), (y + z)};
		pair<ll, ll> R = {(b * y + x * z), (y + z)};
		cout << fixed << setprecision(30) << (SUMA(R) - SUMA(L)) * ld(ld(1.0) + ld(z) / ld(y)) << "\n";
	}
}