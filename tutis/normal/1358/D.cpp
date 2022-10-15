/*input
5 6
4 2 3 1 3

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
	ll n, x;
	cin >> n >> x;
	vector<ll>d(n);
	cin >> d;
	reverse(d.begin(), d.end());
	while (d.size() < 2 * n + 10)
		d.push_back(d[(int)d.size() - n]);
	ll ans = 0;
	ll sumd[2 * n + 3];
	ll sumx[2 * n + 3];
	sumd[0] = 0;
	sumx[0] = 0;
	for (int i = 1; i < 2 * n + 3; i++)
	{
		sumd[i] = sumd[i - 1] + d[i];
		sumx[i] = sumx[i - 1] + d[i] * (d[i] + 1) / 2;
	}
	int j = 0;
	for (int i = 1; i <= n; i++)
	{
		j = max(j, i);
		while (sumd[j] - sumd[i - 1] < x)
			j++;
		ll gal = sumd[j - 1] - sumd[i - 1];
		ll a0 = d[j];
		ll kiek = (x - gal);
		ll a1 = a0 - kiek + 1;
		ans = max(ans, sumx[j - 1] - sumx[i - 1] + (a0 + a1) * kiek / 2);
	}
	cout << ans << "\n";
	return 0;
}