/*input
7 -475391
qohshra
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
	ll n;
	ll T;
	string s;
	cin >> n >> T >> s;
	auto f = [&](char c)->ll
	{
		ll pos = c - 'a';
		return 1ll << pos;
	};
	T -= f(s.back());
	s.pop_back();
	if (!s.empty())
	{
		T += f(s.back());
		s.pop_back();
	}
	ll cnt[27];
	for (ll i = 0; i < 27; i++)
		cnt[i] = 0;
	for (char &c : s)
	{
		T += f(c);
		c++;
		cnt[c - 'a']++;
	}
	for (ll i = 26; i >= 0; i--)
	{
		if (T >= 0)
		{
			ll c = T / (1ll << i);
			c = min(c, cnt[i]);
			T -= (1ll << i) * c;
		}
	}
	if (T == 0)
	{
		cout << "Yes\n";
	}
	else
		cout << "No\n";
}