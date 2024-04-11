/*input
4
1 3 3 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

const ll modulo = 998244353;
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
	int n;
	cin >> n;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	reverse(a.begin(), a.end());
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = mod(ans + a[i] * mod(power(2, i + 1 - 2) * (i + 1 + 1)));
	cout << ans << "\n";
}