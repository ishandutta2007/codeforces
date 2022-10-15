/*input
4 10
2 4 1 4
3 2
4 2
4 1
3 1
4 1
1 3
3 2
2 1
3 1
2 4

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
	int n, m;
	cin >> n >> m;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<pair<int, int>>adj[n + 1];
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x]--;
		a[y]--;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}
	vector<int>A;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= 0)
			A.push_back(i);
	}
	vector<int>T;
	vector<bool>jau(m + 1, false);
	while (!A.empty())
	{
		int x = A.back();
		A.pop_back();
		for (pair<int, int>j : adj[x])
		{
			if (jau[j.second] == false)
			{
				jau[j.second] = true;
				T.push_back(j.second);
				a[j.first]++;
				if (a[j.first] == 0)
					A.push_back(j.first);
			}
		}
	}
	if (T.size() == m)
	{
		cout << "ALIVE\n";
		reverse(T.begin(), T.end());
		for (int i : T)
			cout << i << " ";
		cout << "\n";
	}
	else
		cout << "DEAD\n";
	return 0;
}