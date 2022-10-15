/*input
4
5 2
2 3 4 4 3
3 1
2 10 1000
4 5
0 1 1 100
1 8
89

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
const ll mod = 1000000007;
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
			calc___ = true;
			I___[1] = 1;
			I___[0] = 0;
			for (ll i = 2; i < maxinv; ++i)
				I___[i] = (mod - (mod / i) * I___[mod % i] % mod) % mod;
		}
		return I___[x];
	}
	return power(x, mod - 2);
}
}
int n, p;
void pridek(map<ll, ll, greater<ll>>&A, ll x)
{
	A[x]++;
	while (A[x] == p)
	{
		A[x] = 0;
		A[x + 1]++;
		x++;
	}
}
void bal(map<ll, ll, greater<ll>>&A, map<ll, ll, greater<ll>>&B)
{
	auto ita = A.begin();
	auto itb = B.begin();
	if (ita->first >= 0 && ita->second == 0)
	{
		A.erase(ita);
		return bal(A, B);
	}
	if (itb->first >= 0 && itb->second == 0)
	{
		B.erase(itb);
		return bal(A, B);
	}
	if (ita->first == itb->first)
	{
		if (ita->first >= 0)
		{
			int c = min(ita->second, itb->second);
			ita->second -= c;
			itb->second -= c;
			if (ita->second == 0)
			{
				A.erase(ita);
			}
			if (itb->second == 0)
			{
				B.erase(itb);
			}
			if (c != 0)
				return bal(A, B);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		int k[n];
		for (int i = 0; i < n; i++)
			cin >> k[i];
		sort(k, k + n, greater<int>());
		if (p == 1)
		{
			cout << n % 2 << "\n";
			continue;
		}
		map<ll, ll, greater<ll>>A;
		map<ll, ll, greater<ll>>B;
		A[-1] = 0;
		B[-1] = 0;
		auto AAA = [&]()
		{
			auto ita = A.begin();
			auto itb = B.begin();
			if (ita->first != itb->first)
				return ita->first > itb->first;
			return ita->second > itb->second;
		};
		ll ret = 0;
		for (ll i : k)
		{
			if (!AAA())
			{
				pridek(A, i);
				ret += power(p, i);
			}
			else
			{
				pridek(B, i);
				ret -= power(p, i);
			}
			bal(A, B);
			if (ret >= mod)
				ret -= mod;
			if (ret < 0)
				ret += mod;
		}
		if (!AAA())
			ret = (mod - ret) % mod;
		cout << ret << "\n";
	}
	return 0;
}