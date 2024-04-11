/*input
8
1 2 3 4 5 6 7 8

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
ll r(ll v)
{
	ll x = sqrt(v);
	while (x * x > v)
		x--;
	while ((x + 1) * (x + 1) <= v)
		x++;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	ll delt = a[n - 1] - a[0];
	vector<ll>p;
	for (int i = 1; i < n; i++)
		p.push_back(a[i]);
	shuffle(p.begin(), p.end(), rng);
	for (ll k = 1;; k++)
	{
		ll v0 = k * k;
		ll v1 = v0 + k;
		if (v1 < a[0])
			continue;
		bool ok = true;
		ll del0 = k * k - a[0];
		ll d0 = 0;
		ll d1 = k;
		if (del0 < 0)
			d0 = max(d0, -del0);
		if (d0 > d1)
			continue;
		for (ll i : p)
		{
			ll v = del0 + i;
			ll k1 = r(v);
			ll del = v - k1 * k1;
			if (del <= k1)
			{
				d1 = min(d1, k1 - del);
			}
			else
			{
				//d0 = max(d0, (k1 + 1) * (k1 + 1) - v);
				d0 = max(d0, 2 * k1 + 1 - del);
			}
			if (d0 > d1)
				break;
		}
		if (d0 <= d1)
		{
			cout << del0 + d0 << "\n";
			return 0;
		}
	}
}