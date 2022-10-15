/*input
4 3
2 3 5 6

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
ll n, p;
struct ST
{
	ll l, r, mn = 0, lazy = 0;
	ST *left, *right;
	ST(ll x, ll y)
	{
		l = x;
		r = y;
		if (x < y)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		if (lazy != 0)
		{
			if (l < r)
			{
				left->lazy += lazy;
				right->lazy += lazy;
			}
			mn += lazy;
			lazy = 0;
		}
	}
	void add(ll x, ll y, ll w)
	{
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		fix();
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		mn = min(left->mn, right->mn);
	}
	ll nxt(ll i)
	{
		if (r < i)
			return -1;
		fix();
		if (mn != 0)
			return -1;
		if (l < r)
		{
			ll x = left->nxt(i);
			if (x != -1)
				return x;
			return right->nxt(i);
		}
		else
			return l;
	}
	ll get(ll v)
	{
		v = max(v, 0ll);
		ll a = v / p;
		ll b = v % p;
		ll x = nxt(b);
		if (x != -1)
		{
			return a * p + x;
		}
		x = nxt(0);
		if (x == -1)
			return -1;
		return (a + 1) * p + x;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> p;
	ST medis(0, p - 1);
	ll a[n + 1];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 1e13;
	sort(a, a + n);
	vector<ll>ret;
	ll mn = 0;
	for (ll i = 0; i < n; i++)
		mn = max(mn, a[i] - i);
	vector<pair<ll, ll>>bl;
	bl.push_back({ -1, -1});
	bl.push_back({0, mn - 1});
	map<ll, vector<pair<pair<ll, ll>, ll>>>M;
	for (ll j = 0; j < n; j++)
	{
		if (a[j] == a[j + 1])
			continue;
		if (a[j + 1] - a[j] < p)
		{
			ll i1 = (j + 1) % p;
			ll i2 = i1 + p * ((n - i1) / p);
			ll x = a[j] - i1;
			ll y = a[j + 1] - i1 - 1;
			assert(y - x + 1 < p);
			assert(x <= y);
			assert(i2 >= i1);
			x %= p;
			y %= p;
			if (x < 0)
				x += p;
			if (y < 0)
				y += p;
			M[a[j] - i2].push_back({{x, y}, 1});
			M[a[j] - i1].push_back({{x, y}, -1});
			bl.push_back({a[j] - i1, a[j + 1] - i1 - 1});
			bl.push_back({a[j] - i2, a[j + 1] - i2 - 1});
		}
		else
		{
			ll i1 = (j + 1) % p;
			ll i2 = i1 + p * ((n - i1) / p);
			if (i2 == n)
				i2 -= p;
			bl.push_back({a[j] - i2, a[j + 1] - i1 - 1});
		}
	}
	sort(bl.begin(), bl.end());
	vector<pair<ll, ll>>bll;
	ll mx = -2;
	ll mn1 = -1;
	for (pair<ll, ll>i : bl)
	{
		if (i.first > mx + 1)
		{
			bll.push_back({mn1, mx});
			mn1 = i.first;
			mx = i.second;
		}
		else
			mx = max(mx, i.second);
	}
	bll.push_back({mn1, mx});
	vector<ll>ans;
	for (ll i = 0; i + 1 < bll.size(); i++)
	{
		while (!M.empty() && M.begin()->first <= bll[i].second)
		{
			for (pair<pair<ll, ll>, ll>x : M.begin()->second)
			{
				ll a = x.first.first;
				ll b = x.first.second;
				ll w = x.second;
				if (a <= b)
				{
					medis.add(a, b, w);
				}
				else
				{
					medis.add(0, b, w);
					medis.add(a, p - 1, w);
				}
			}
			M.erase(M.begin());
		}
		for (ll x = medis.get(bll[i].second + 1); x < bll[i + 1].first && x != -1; x = medis.get(x + 1))
			ans.push_back(x);
	}
	cout << ans.size() << "\n";
	for (ll i : ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}