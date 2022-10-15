/*input
1
963973652
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
const ll maxsz = 300001;
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
bool prime(ll a)
{
	if (a <= 1)
		return false;
	for (ll b = 2; b * b <= a; b++)
	{
		if (a % b == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll c = 1;
	vector<ll>A;
	vector<ll>P;
	int kiek = 0;
	for (ll x = 2; x <= 631; x++)
	{
		if (prime(x))
		{
			P.push_back(x);
		}
	}
	while (true)
	{
		shuffle(P.begin(), P.end(), rng);
		A.clear();
		A.push_back(1);
		for (ll i : P)
		{
			if (A.back() <= 1e18 / i)
				A.back() *= i;
			else
				A.push_back(i);
		}
		if (A.size() == 15)
			break;
	}
	int test;
	cin >> test;
	while (test--)
	{
		vector<ll>T;
		ll x = 1;
		for (int i = 0; i < A.size(); i++)
		{
			kiek++;
			cout << "? " << A[i] << endl;
			ll q;
			cin >> q;
			vector<ll>G;
			vector<ll>PP;
			for (ll p : P)
			{
				if (q % p == 0)
				{
					ll t = 1;
					ll alfa = 0;
					while (alfa <= 1 || t * p <= 1e4)
					{
						alfa++;
						t *= p;
					}
					if (t == 1)
						continue;
					T.push_back(t);
				}
			}
		}
		for (int i = 0; i < T.size();)
		{
			ll c = T[i];
			i++;
			while (i < T.size() && T[i] < 1e18 / c)
			{
				c *= T[i];
				i++;
			}
			kiek++;
			if (kiek == 18)
				break;
			cout << "? " << c << endl;
			ll q;
			cin >> q;
			for (ll p : P)
			{
				int alfa = 0;
				while (q % p == 0)
				{
					q /= p;
					alfa++;
				}
				x *= alfa + 1;
			}
		}
		cout << "! " << max(x + 7, 2 * x) << endl;
	}
	return 0;
}