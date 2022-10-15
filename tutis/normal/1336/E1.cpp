/*input
4 4
3 5 8 14

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
namespace {
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
const ll maxsz = 10;
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
}
vector<vector<ll>> s1(18, vector<ll>(1 << 18, 0));
vector<ll> s2(1 << 18, 0);
ll ans[40];
void fwht(vector<ll>& P, bool inver) {
	for (ll len = 1; 2 * len <= (1 << 18); len <<= 1) {
		for (ll i = 0; i < (1 << 18); i += 2 * len) {
			for (ll j = 0; j < len; j++) {
				ll u = P[i + j];
				ll v = P[i + len + j];
				P[i + j] = u + v;
				if (P[i + j] >= mod)
					P[i + j] -= mod;
				P[i + len + j] = u - v;
				if (P[i + len + j] < 0)
					P[i + len + j] += mod;
			}
		}
	}

	if (inver) {
		ll c = inv(1 << 18);
		for (ll i = 0; i < (1 << 18); i++)
			P[i] = (P[i] * c) % mod;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll k0 = 0;
	vector<ll>X;
	while (n--)
	{
		ll a;
		cin >> a;
		for (ll i : X)
		{
			if ((i ^ a) < a)
				a ^= i;
		}
		if (a == 0)
			k0++;
		else
		{
			X.push_back(a);
			sort(X.begin(), X.end(), greater<ll>());
		}
	}
	assert((ll)X.size() <= 35);
	ll pk0 = power(2, k0);
	vector<ll>Y, Z;
	for (ll i : X)
		if (i < (1ll << 18))
			Y.push_back(i);
		else
			Z.push_back(i);
	for (ll t = 0; t < (1 << (ll)Y.size()); t++)
	{
		ll val = 0;
		for (ll i = 0; i < (ll)Y.size(); i++)
			if ((t & (1 << i)) != 0)
				val ^= Y[i];
		s2[val]++;
	}
	for (ll t = 0; t < (1 << (ll)Z.size()); t++)
	{
		ll val = 0;
		for (ll i = 0; i < (ll)Z.size(); i++)
			if ((t & (1 << i)) != 0)
				val ^= Z[i];
		ll x = val % (1 << 18);
		ll y = val / (1 << 18);
		s1[__builtin_popcount(y)][x]++;
	}
	fwht(s2, false);
	for (ll a = 0; a < 18; a++)
	{
		fwht(s1[a], false);
	}
	for (ll a = 0; a < 18; a++)
	{
		vector<ll> x(1 << 18);
		for (ll s = 0; s < (1 << 18); s++)
		{
			x[s] = (s1[a][s] * s2[s]) % mod;
		}
		fwht(x, true);
		for (ll s = 0; s < (1 << 18); s++)
		{
			ans[a + __builtin_popcount(s)] += x[s];
		}
	}
	for (ll i = 0; i <= m; i++)
	{
		ans[i] %= mod;
		if (ans[i] < 0)
			ans[i] += mod;
		cout << (ans[i]*pk0) % mod << " ";
	}
	return 0;
}