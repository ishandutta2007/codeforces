/*input
6
4
0110
6
011011
5
01010
20
10001111110110111000
20
00110110100110111101
20
11101111011000100010

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 998244353;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
ll F(ll n)
{
	ll ret = 1;
	for (int i = 2; i <= n; i++)
	{
		ret *= i;
		ret %= mod;
	}
	return ret;
}
ll C(ll n, ll k)
{
	if (k < 0 || n - k < 0 || n < 0)
		return 0;
	return (F(n) * power(F(k) * F(n - k), -1)) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int g = 0;
		int c2 = 0;
		int c1 = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '1')
				g++;
			else
			{
				c2 += g / 2;
				c1 += g % 2;
				g = 0;
			}
		}
		c2 += g / 2;
		c1 += g % 2;
		cout << C(n - c2 - c1, c2) << "\n";
	}

}