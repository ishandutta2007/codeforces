/*input
40 37 65
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000003;

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
ll w, h;
map<int, int>X;
ll ans(ll c)
{
	if (c <= 0)
		return 1;
	if (X.count(c))
		return X[c];
	if (c <= w)
		return X[c] = power(h + 1, c);
	ll ret = 0;
	ll m = c / 2;
	{	//sz = 0
		ret += ans(m) * ans(c - m - 1);
		ret %= modulo;
	}
	ll x = 1;
	for (int sz = 1; sz <= w; sz++)
	{
		x *= h;
		x %= modulo;
		for (int t = 0; t < sz && m - t >= 0; t++)
		{
			if (c - (m - t + sz) >= 0)
				ret += x * ans(m - t - 1) * ans(c - (m - t + sz) - 1);
			ret %= modulo;
		}
	}
	return X[c] = ret;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll c;
	cin >> c >> w >> h;
	cout << ans(c) << "\n";
}