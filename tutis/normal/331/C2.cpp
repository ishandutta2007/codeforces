/*input
26140127906
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mxd(ll x)
{
	ll r = 1;
	while (x > 0)
	{
		r = max(r, x % 10);
		x /= 10;
	}
	return r;
}
pair<ll, ll>dp(ll mx, ll x)
{
	pair<ll, ll>ret = {0, 0};
	while (x >= 0)
	{
		ret.first++;
		ll k = max(mx, mxd(x));
		ret.second += k;
		x -= k;
	}
	return ret;
}
ll power(ll a, ll b)
{
	ll ret = 1;
	while (b--)
	{
		ret *= a;
	}
	return ret;
}
const pair<ll, ll> NULIS = { -189485, -1894532};
pair<ll, ll> XXX[10][20][10];
pair<ll, ll>dp(ll mx, ll k, ll g)
{
	if (XXX[mx][k][g] != NULIS)
		return XXX[mx][k][g];
	if (k == 0)
	{
		return XXX[mx][k][g] = dp(mx, g);
	}
	if (k == 1)
	{
		return XXX[mx][k][g] = dp(mx, 90 + g);
	}
	if (k == 2)
	{
		return XXX[mx][k][g] = dp(mx, 990 + g);
	}
	ll G = g;
	pair<ll, ll>ret = {0, 0};
	ll x = power(10, k + 1) - 10 + g;
	ll a = 9;
	while (x >= 0)
	{
		pair<ll, ll>c = dp(max(mx, a), k - 1, g);
		x -= c.second;
		g = x % 10;
		a--;
		ret.first += c.first;
		ret.second += c.second;
	}
	return XXX[mx][k][G] = ret;
}
pair<ll, ll> k_mx(ll n)
{
	n /= 10;
	ll ret = 0;
	while (n % 10 == 9 && n > 9)
	{
		ret++;
		n /= 10;
	}
	return {ret, mxd(n)};
}
ll ans(ll n)
{
	if (n <= 0)
		return 0;
	if (n <= 1e6 || k_mx(n).first == 0)
		return 1 + ans(n - mxd(n));
	pair<ll, ll>y = dp(k_mx(n).second, k_mx(n).first, n % 10);
	return y.first + ans(n - y.second);
}
int main()
{
	clock_t pradzia = clock();
	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 20; b++)
		{
			for (int c = 0; c < 10; c++)
			{
				XXX[a][b][c] = NULIS;
			}
		}
	}
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	cout << ans(n) << "\n";
	cerr << double(clock() - pradzia) / CLOCKS_PER_SEC << '\n';
}