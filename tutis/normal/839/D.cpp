/*input
4
2 3 4 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll mod(ll x, ll m = modulo)
{
	x %= m;
	x += m;
	x %= m;
	return x;
}
ll power(ll x, ll a)
{
	x = mod(x);
	a = mod(a, modulo - 1);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, -1);
}
ll interpolate(vector<ll> &x, vector<ll> &y, ll X)
{
	for (ll i = 0; i < x.size(); i++)
		if (x[i] == X)
			return y[i];
	ll ret = 0;
	for (ll i = 0; i < x.size(); i++)
	{
		ll a = y[i];
		ll b = 1;
		for (ll j = 0; j < x.size(); j++)
		{
			if (j == i)
				continue;
			a = mod(a * mod(X - x[j]));
			b = mod(b * mod(x[i] - x[j]));
		}
		ret = mod(ret + a * inv(b));
	}
	return ret;
}
ll dp[1000001];
ll CNT[1000001];
int main()
{
	ll n;
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		CNT[a]++;
	}
	ll ans = 0;
	for (int i = 1000000; i > 1; i--)
	{
		for (int j = i; j <= 1000000; j += i)
			dp[i] += CNT[j];
		dp[i] = mod(dp[i] * power(2, dp[i] - 1));
		for (int j = 2 * i; j <= 1000000; j += i)
			dp[i] = mod(dp[i] - dp[j]);
		ans = mod(ans + dp[i] * i);
	}
	cout << ans << "\n";
}