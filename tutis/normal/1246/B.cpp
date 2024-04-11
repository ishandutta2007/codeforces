/*input
6 3
1 3 9 8 24 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll INF = 1e7;
ll p(ll n, ll k)
{
	if (k == 0)
		return 1;
	if (k % 2 == 1)
		return min(INF, n * p(min(INF, n * n), k / 2));
	else
		return p(min(INF, n * n), k / 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		for (ll x = 2; p(x, k) <= a[i]; x++)
		{
			while ((a[i] % p(x, k)) == 0)
				a[i] /= p(x, k);
		}
	}
	ll ans = 0;
	map<ll, ll>K;
	for (ll i = 0; i < n; i++)
	{
		ll x = a[i];
		ll y = 1;
		for (ll p_ = 2; p_ <= 320; p_++)
		{
			ll alfa = 0;
			while (x % p_ == 0)
			{
				x /= p_;
				alfa++;
			}
			if (alfa > 0)
				y *= p(p_, k - alfa);
			y = min(y, INF);
		}
		if (x != 1)
			y *= p(x, k - 1);
		y = min(y, INF);
		ans += K[y];
		K[a[i]]++;
	}
	cout << ans << "\n";
}