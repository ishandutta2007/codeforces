/*input
7
1 0
20 1
42 7
13 7
99 1
99 0
127 7
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
const ll maxinv = 30;
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
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	y %= (mod - 1);
	if (y < 0)
		y += mod - 1;
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
ll I___[maxinv];
bool calc___ = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxinv)
	{
		if (!calc___)
		{
			assert(maxinv <= mod);
			calc___ = true;
			I___[1] = 1;
			I___[0] = 0;
			for (ll i = 2; i < maxinv; ++i)
			{
				I___[i] = -(mod / i) * I___[mod % i];
				I___[i] %= mod;
				if (I___[i] < 0)
					I___[i] += mod;
			}
		}
		return I___[x];
	}
	return power(x, mod - 2);
}
}
ll f(ll x)
{
	assert(x >= 0);
	ll ans = 0;
	for (char c : to_string(x))
		ans += c - '0';
	return ans;
}
ll ff(ll n, ll k)
{
	assert(n <= 1e18);
	if (n < 0)
		return -1;
	ll sum = 0;
	for (int i = 0; i <= k; i++)
		sum += f(n + i);
	return sum;
}
ll ans(ll n, ll k)
{
	ll ans = -1;
	for (ll last = 0; last <= 9; last++)
	{
		ll del = 0;
		ll kar9 = 0;
		bool big = false;
		for (ll d = 0; d <= k; d++)
		{
			del += (last + d) % 10;
			if (last + d >= 10)
			{
				del++;
				big = true;
			}
			else
				kar9++;
		}
		for (ll k9 = 0; k9 * kar9 * 9 <= n; k9++)
		{
			ll x = (n - del - k9 * kar9 * 9) / (k + 1);
			if (x >= 0) {
				string s = string(1, '0' + last) + string(k9, '9');
				bool did = big;
				while (x > 0)
				{
					ll l = min(9ll, x);
					if (did)
						l = min(8ll, l);
					did = false;
					s += '0' + l;
					x -= l;
				}
				reverse(s.begin(), s.end());
				ll gal = stoll(s);
				if (ff(gal, k) == n)
				{
					if (ans == -1)
						ans = stoll(s);
					else
						ans = min(ans, stoll(s));
				}
			}
		}
	}
	if (ans != -1)
		assert(ff(ans, k) == n);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	/*
	for (int n = 0; n <= 150; n++)
	{
		for (int k = 0; k <= 9; k++)
		{
			ll mn = -1;
			for (ll x = 0; x <= 1000; x++)
				if (ff(x, k) == n)
				{
					mn = x;
					break;
				}
			if (mn == -1)
			{
				//cout << n << " " << k << ": " << ans(n, k) << "\n";
			}
			else
			{
				//if (mn != ans(n, k))
				//	cout << n << " " << k << ": " << ans(n, k) << " " << mn << "\n";
				//assert(mn == ans(n, k));
			}
		}
	}*/
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		cout << ans(n, k) << "\n";
	}
	return 0;
}