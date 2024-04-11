/*input
3
30 10 20
41 15 30
18 13 18
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
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		ll h, c, t;
		cin >> h >> c >> t;
		if (t == h)
		{
			cout << "1\n";
			continue;
		}
		if (t * 2 <= c + h)
		{
			cout << "2\n";
			continue;
		}
		ll ck = (t - h) / (c + h - 2 * t);
		ll k = ck;
		for (ll kk : {0ll, 1ll, 2ll, 3ll, ck - 1, ck + 1, ck - 2, ck + 2})
		{
			if (kk < 0)
				continue;
			ld t0 = abs(ld(t) - ld(k * (c + h) + h) / ld(2 * k + 1));
			ld t1 = abs(ld(t) - ld(kk * (c + h) + h) / ld(2 * kk + 1));
			if (abs(t0 - t1) <= 1e-13)
				k = min(k, kk);
			else if (t1 < t0)
				k = kk;
		}
		cout << 2 * k + 1 << "\n";
	}
	return 0;
}