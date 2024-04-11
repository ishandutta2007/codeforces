/*input
12
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
ll k[25];
ll f(ll x)
{
	if (x == 0)
		return 1;
	return (x * f(x - 1)) % modulo;
}
ll power(ll a, ll b)
{
	a %= modulo;
	if (b == 0)
		return 1;
	if (b % 2 == 1)
		return (power(a, b - 1) * a) % modulo;
	ll x = power(a, b / 2);
	return (x * x) % modulo;
}
ll F[1010101];
ll C(ll n, ll k)
{
	k = min(k, n - k);
	if (k < 0 || n < 0)
		return 0;
	if (k == 0)
		return 1;
	return (F[n] * power(F[k] * F[n - k], modulo - 2)) % modulo;
}
ll ans(ll n, ll x)
{
	if (k[x] == 0)
		return 0;
	if (x == 0)
	{
		return f(n);
	}
	ll a = ans(n - k[x], x - 1);
	ll sz = n - k[x];
	ll sz1 = n - 1;
	ll t = 1;
	a *= f(k[x]);
	a %= modulo;
	a *= C(sz1, sz);
	a %= modulo;
	return a;
}
ll brute(ll n, ll mx)
{
	ll a[n];
	iota(a, a + n, 1);
	ll ret = 0;
	do
	{
		ll g = a[0];
		ll k = 1;
		for (ll i = 1; i < n; i++)
		{
			ll g_ = __gcd(g, a[i]);
			if (g_ != g)
				k++;
			g = g_;
		}
		if (k == mx)
			ret++;
	} while (next_permutation(a, a + n));
	return ret;
}
int main()
{
	F[0] = 1;
	for (ll i = 1; i < 1010101; i++)
		F[i] = (i * F[i - 1]) % modulo;
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if (n == 2)
	{
		cout << "1\n";
		return 0;
	}
	if (n == 3)
	{
		cout << "4\n";
		return 0;
	}
	ll mx = 0;
	for (ll i = 1; i <= n; i++)
	{
		k[__builtin_ctz(i)]++;
		mx = max(mx, (ll)__builtin_ctzll(i));
	}
	map<ll, ll>MA;
	for (ll x = 1; x <= n; x++)
	{
		ll y = x;
		ll s = 1;
		while (y % 3 == 0)
		{
			y /= 3;
			s *= 3;
		}
		while (y % 2 == 0)
		{
			y /= 2;
			s *= 2;
		}
		MA[s]++;
	}
	if (n >= 10)
	{
		ll ret = ans(n, mx);
		ll b = ((1 << mx) / 2) * 3;
		if (b <= n)
		{
			for (ll c = b; c >= 3; c /= 2)
			{
				vector<ll>a;
				for (ll i = 1; i <= c / 3; i *= 2)
					a.push_back(i);
				for (ll i = c; i <= b; i *= 2)
					a.push_back(i);
				for (ll i = 0; i < a.size(); i++)
					k[i] = 0;
				for (pair<ll, ll>i : MA)
				{
					int c = 0;
					for (int j = 0; j < a.size(); j++)
						if (__gcd(i.first, a[j]) == a[j])
							c = j;
					k[c] += i.second;
				}
				ret += ans(n, (int)a.size() - 1);
				ret %= modulo;
			}
		}
		cout << ret << "\n";
	}
	else
	{
		cout << brute(n, mx + 1) << "\n";
	}
}