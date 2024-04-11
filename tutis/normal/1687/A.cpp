/*input
4
5 2
5 6 1 2 3
5 7
5 6 1 2 3
1 2
999999
5 70000
1000000000 1000000000 1000000000 1000000000 1000000000
*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll a[n + 1];
		a[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] += a[i - 1];
		}
		ll ret1 = 0;
		if (k > n)
		{
			ret1 += n * (k - n);
			k = n;
		}
		ll ret = (k) * (k - 1) / 2;
		ll ad = 0;
		for (ll i = k; i <= n; i++)
			ad = max(ad, a[i] - a[i - k]);
		cout << ret + ad + ret1 << "\n";
	}
}