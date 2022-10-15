/*input
5
2 2 3
7 8
6 3
3 1 4
1 1 1
1
1
1000000000
2 2 2
1 2
5 4
6 7
2 2 2
1 2
3 4
6 7
3 4 1
3 2 1
7 3 3 4
6
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
const ll mod = 1000000007;
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		vector<ll>s(3);
		cin >> s;
		vector<ll>x[3];
		for (int t = 0; t < 3; t++)
		{
			x[t] = vector<ll>(s[t]);
			cin >> x[t];
			sort(x[t].begin(), x[t].end());
		}
		ll ans = 4e18;
		for (int a : {0, 1, 2}) {
			for (int b : {0, 1, 2})
			{
				for (int c : {0, 1, 2})
				{
					if (a == b || b == c || a == c)
						continue;
					for (ll x1 : x[a])
					{
						auto it = lower_bound(x[c].begin(), x[c].end(), x1);
						if (it != x[c].end())
						{
							ll x3 = *it;
							int k = lower_bound(x[b].begin(), x[b].end(), (x1 + x3) / 2)
							        - x[b].begin();
							for (int d = -1; d <= 1; d++)
							{
								int i = k + d;
								if (i >= 0 && i < s[b])
								{
									ll x2 = x[b][i];
									ans = min(ans, 2 * (x1 * x1 +
									                    x2 * x2 +
									                    x3 * x3 -
									                    x1 * x2 -
									                    x1 * x3 -
									                    x2 * x3));
								}
							}
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}