/*input
01101001
5 7

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll x, y;
	cin >> x >> y;
	function<pair<int, vector<ll>>(int, int)>f = [&](int l, int r)->pair<int, vector<ll>>
	{
		if (l == r)
		{
			if (s[l] == '?')
			{
				return {0, {0ll, 0ll}};
			}
			else if (s[l] == '0')
			{
				return {1, {0ll}};
			}
			else
			{
				return {0, {0ll}};
			}
		}
		else
		{
			int i = (l + r) / 2;
			pair<int, vector<ll>>A = f(l, i);
			pair<int, vector<ll>>B = f(i + 1, r);
			int n = (int)A.second.size() - 1;
			int m = (int)B.second.size() - 1;
			vector<ll>ret(n + m + 1);
			for (int s = 0; s <= n + m; s++)
			{
				auto f = [&](int a)
				{
					ll k01 = A.first + a;
					ll k11 = (i - l + 1) - k01;
					ll k02 = B.first + (s - a);
					ll k12 = (r - i) - k02;
					return k01 * k12 * x + k11 * k02 * y + A.second[a] + B.second[s - a];
				};
				int lo = max(0, s - m);
				int hi = min(s, n);
				while (hi - lo + 1 >= 4)
				{
					int c = (lo + hi) / 2;
					ll f1 = f(c);
					ll f2 = f(c + 1);
					if (f1 <= f2)
						hi = c;
					else
						lo = c + 1;
				}
				ret[s] = f(lo);
				for (int a = lo + 1; a <= hi; a++)
					ret[s] = min(ret[s], f(a));
			}
			return {A.first + B.first, ret};
		}
	};
	vector<ll>ans = f(0, (int)s.size() - 1).second;
	ll ret = ans[0];
	for (ll i : ans)
		ret = min(ret, i);
	cout << ret << "\n";
}