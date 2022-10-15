/*input
5 3
1 2
2 3
4 5
2 1 2 2 1

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int t[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	int p[n];
	iota(p, p + n, 1);
	sort(p, p + n, [&](int a, int b) {return t[a] < t[b];});
	bool ok = true;
	for (int i : p)
	{
		set<int>v;
		for (int j : adj[i])
		{
			if (t[j] == t[i])
				ok = false;
			if (t[j] > t[i])
				continue;
			v.insert(t[j]);
		}
		if (v.size() != t[i] - 1)
			ok = false;
	}
	if (!ok)
		cout << "-1\n";
	else {
		for (int i : p)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}