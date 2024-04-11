/*input
7 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(0);
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
}
const ll mod = 998244353;
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
const ll maxsz = 30;
ll I[maxsz];
bool calc = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxsz)
	{
		if (!calc)
		{
			calc = true;
			I[1] = 1;
			I[0] = 0;
			for (ll i = 2; i < maxsz; ++i)
				I[i] = (mod - (mod / i) * I[mod % i] % mod) % mod;
		}
		return I[x];
	}
	return power(x, mod - 2);
}
ll F[505050];
ll iF[505050];
ll C(ll x, ll y)
{
	if (x < 0 || y < 0 || x - y < 0)
		return 0;
	return (F[x] * ((iF[y] * iF[x - y]) % mod)) % mod;
}

int main()
{
	F[0] = iF[0] = 1;
	for (int i = 1; i < 505050; i++)
	{
		F[i] = (F[i - 1] * i) % mod;
		iF[i] = inv(F[i]);
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (ll m = 1; m <= n; m++)
	{
		ll a = (n / m - 1);
		ll b = k - 1;
		ans += C(a, b);
		if (ans >= mod)
			ans -= mod;
	}
	cout << ans << "\n";
	return 0;
}