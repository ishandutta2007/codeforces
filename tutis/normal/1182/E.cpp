/*input
17 97 41 37 11

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(12938712983ll);
const ll modulo = 1000000007;
const ll mod1 = 1000000006;
vector<ll>operator*(vector<vector<ll>>a, vector<ll>b)
{
	ll n = a.size();
	vector<ll>ret(n, 0);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			ret[i] += a[i][j] * b[j];
			ret[i] %= mod1;
		}
	}
	return ret;
}
vector<vector<ll>>operator*(vector<vector<ll>>a, vector<vector<ll>>b)
{
	ll n = a.size();
	vector<vector<ll>>c(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			for (ll k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= mod1;
			}
		}
	}
	return c;
}
vector<vector<ll>>power(vector<vector<ll>>a, ll k)
{
	ll n = a.size();
	if (k == 0)
	{
		vector<vector<ll>>a(n, vector<ll>(n, 0));
		for (ll i = 0; i < n; i++)
			a[i][i] = 1;
		return a;
	}
	if (k == 1)
		return a;
	if (k % 2 == 1)
		return power(a, k - 1) * a;
	vector<vector<ll>>b = power(a, k / 2);
	return b * b;
}
ll power(ll a, ll b)
{
	if (b == 0)
		return 1;
	if (b % 2 == 1)
	{
		ll x = power(a, b - 1);
		x *= a;
		x %= modulo;
		return x;
	}
	ll x = power(a, b / 2);
	x *= x;
	x %= modulo;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, f1, f2, f3, C;
	cin >> n >> f1 >> f2 >> f3 >> C;
	ll k = n - 3;
	vector<vector<ll>>x = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
	x = power(x, k);
	vector<ll>aa = {0, 0, 0, 2, 1};
	vector<ll>bb = {0, 0, 1};
	vector<ll>cc = {0, 1, 0};
	vector<ll>dd = {1, 0, 0};
	bb = x * bb;
	cc = x * cc;
	dd = x * dd;
	aa = power({
		{1, 1, 1, 1, 0},
		{1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0},
		{0, 0, 0, 1, 2},
		{0, 0, 0, 0, 1}
	}, k) * aa;
	ll ans = power(C, aa[0]);
	ans *= power(f1, bb[0]);
	ans %= modulo;
	ans *= power(f2, cc[0]);
	ans %= modulo;
	ans *= power(f3, dd[0]);
	ans %= modulo;
	cout << ans << "\n";
}