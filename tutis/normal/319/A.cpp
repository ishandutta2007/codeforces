/*input
1
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
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll ans = 0;
	string x;
	cin >> x;
	reverse(x.begin(), x.end());
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] == '1')
			ans += power(2, x.size() + i - 1);
		ans %= modulo;
	}
	cout << ans << "\n";
}