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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, p;
	cin >> n >> p;
	int a[n + 1];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = 1e9 + 1e8;
	sort(a, a + n);
	vector<int>ret;
	int mn = 0;
	for (int i = 0; i < n; i++)
		mn = max(mn, a[i] - i);
	vector<pair<int, int>>bl;
	bl.push_back({ -1, -1});
	bl.push_back({0, mn - 1});
	for (int j = 0; j < n; j++)
	{
		if (a[j] == a[j + 1])
			continue;
		if (a[j + 1] - a[j] < p)
		{
			for (int i = (j + 1) % p; a[j + 1] - i - 1 >= 0; i += p)
			{
				bl.push_back({a[j] - i, a[j + 1] - i - 1});
			}
		}
		else
		{
			int i1 = (j + 1) % p;
			int i2 = i1 + p * ((n - i1) / p);
			if (i2 == n)
				i2 -= p;
			bl.push_back({a[j] - i2, a[j + 1] - i1 - 1});
		}
	}
	sort(bl.begin(), bl.end());
	vector<pair<int, int>>bll;
	int mx = -2;
	int mn1 = -1;
	for (pair<int, int>i : bl)
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
	vector<int>ans;
	for (int i = 0; i + 1 < bll.size(); i++)
	{
		for (int x = bll[i].second + 1; x < bll[i + 1].first; x++)
			ans.push_back(x);
	}
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
	cout << "\n";
	return 0;
}